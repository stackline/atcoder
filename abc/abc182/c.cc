#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(2**log10(N) * log10(N))
//
// ### 対数で入力値の桁数を取得
//
// 入力値をN、Nの桁数をkとすると、Nは以下の範囲に存在する。
//
//   10**(k-1) <= N < 10**k
//
// それぞれの値について、低10の対数をとると、
// log10(N) は以下の範囲に存在する。
//
//   log10(10**(k-1)) <= log10(N) < log10(10**k)
//   --> (k-1) <= log10(N) < (k)
//
// これより log10(N).ceil で桁数を求めることができる。
//
//   例: N = 6,227,384 の場合
//   ---
//   irb> Math.log10(6_227_384)
//   => 6.794305646504954
//   irb> Math.log10(6_227_384).ceil
//   => 7
//
// log10(N) で入力値の桁数 7 を取得する。
//
//
// ### bit全探索の計算量
//
// 各桁について 0 (削除する) 1 (削除しない) の2パターンを取る。
// bit全探索のループ回数 = 計算量は 2**(log10(N))
//
//   例: N = 6,227,384 の場合
//   ---
//   irb> 2**Math.log10(6_227_384).ceil
//   => 128
//
//   0000000 〜 1111111 の128パターンを表す。
//
//
// ### bit全探索の計算量を表す式を、解説に掲載のものに変換
//
// 以下の公式を利用する。
//
//   a**(log[b](c)) == c**(log[b](c))
//   ref. https://mathtrain.jp/logexchange
//
// 上記公式を利用して式を変換したのち、指数部を底の変換公式を利用して
// 低 e (= ネイピア数) の対数に変換する。
//
//   2**(log10(N)) = N**(log10(2))
//                 = N**(log(2) / log(10))
//
//
// ### bit全探索の各ループで、残した数の和を求める計算量
//
//   例: n = 6,227,384、bit全探索の2進数 = 1000011 の場合
//   ---
//   bitフラグが立っている桁の数の和を求める。
//
//     6227384
//     1000011
//
//   bitフラグが立っていない桁を削除した後の数字は 684 である。
//   各桁の和は 6 + 8 + 4 = 18 である。
//   各桁の和が 3 で割り切れる数字であるため、3の倍数である。
//   また、削除した桁数 = bitフラグが立っていない桁の数 = 4 である。
//
// bit全探索の2進数について、各桁のbitフラグを確認するため、
// 計算量は log10(N)
//
//
// ### 計算量の最大
//
// N = 10**18 - 1 = 999_999_999_999_999_999 = 約99京 の場合、桁数は 18 である。
//
//   irb> Math.log10(10**18-1)
//   => 18.0
//
// bit全探索の計算量 : 2**(log10(N))
//
//   irb> 2 ** Math.log10(10**18-1)
//   => 262144.0
//
// bit全探索の各ループで、残した数の和を求める計算量 : log10(N)
//
//   irb> Math.log10(10**18-1)
//   => 18.0
//
// トータルの計算量
//
//   2**log10(N) * log10(N)
//   ---
//   (2 ** Math.log10(10**18-1)) * Math.log10(10**18-1)
//   = (2 ** 18) * 18
//   = 4,718,592
//
//   トータルの計算量 = ループ回数は約 471 万回である。
//
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  // k=2
  //   0個消す
  //     3 + 5 = 8 (ng)
  //   1個消す
  //     3 (ok)
  //     5 (ng)
  // k=7
  //   0個消す (7C0 = 1)
  //   1個消す (7C1 = 7)
  //   2個消す (7C2 = 21)
  //   3個消す (7C3 = 7*6*5/3*2*1 = 35)
  //   4個消す (7C4 = 7*6*5*4/4*3*2*1 = 35)
  //   ...
  //   6個消す (7C6 = 7)
  string s;
  cin >> s;

  // 0: 00
  // 1: 01
  // 2: 10
  // 3: 11
  int ans = -1;
  for (int tmp = 0; tmp < (1 << (int)s.size()); tmp++) {
    bitset<18> bs(tmp);
    // bs = "00" つまり、全て消すパターンはスキップする
    if (bs.count() == 0) {
      continue;
    }

    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      // bit が立っている場合は加算する
      if (bs.test(i)) {
        sum += s.at(i) - '0';
      }
    }

    // 3の倍数かどうか判定
    if (sum % 3 == 0) {
      // 消した桁数
      int cnt = s.size() - bs.count();
      if (ans == -1) {
        ans = cnt;
      } else {
        ans = min(ans, cnt);
      }
    }
  }

  cout << ans << endl;
  return 0;
}