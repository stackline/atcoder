#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// エラトステネスの櫛を使って、最小公約数の一覧を求める
vector<int> sieve_of_eratosthenes(int lim) {
  vector<int> d(lim+1);

  // d[i] = i で初期化する
  for (int i = 0; i <= lim; i++) {
    d.at(i) = i;
  }

  // 素数の場合は、そのままである
  // 素数ではない場合は、最小の公約数がセットされる
  // 例
  //    6 = 2 * 3 より d[6] = 2
  //   35 = 5 * 7 より d[35] = 5
  for (int i=2; i <= sqrt(lim); i++) {
    // 素数の場合、
    if (d.at(i) == i) {
      // i=2 の場合、2より大きい2の倍数について、最小の公約数である 2 をセットする
      // 例
      //   4 : j = i*2 --> j = 2*2 --> j = 4
      //   6 : j = j+i --> j = 4+2 --> j = 6
      //   8 : j = j+i --> j = 6+2 --> j = 8
      for (int j = i*2; j < lim; j=j+i) {
        d.at(j) = i;
      }
    }
  }
  return d;
}

// 時間計算量
//   エラトステネスの篩 : O(A + AloglogA)
//   素因数分解 : O(NlogA)
//   素因数の登場回数 : O(A)
//
// 時間計算量の合計
//   O(A + AloglogA + NlogA + A)
//   O(AloglogA + NlogA + 2A)
int main() {
  int n;
  cin >> n;

  int lim = 1e6;

  // 最小公約数 (least common divisor)
  vector<int> lcd_list = sieve_of_eratosthenes(lim);

  // 入力を受け取り、素因数分解する
  vector<int> prime_factor_cnt(lim+1, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    //
    // a=30 の場合
    //   lcd_list[30] = 2
    //   divisor_cnt[2] をインクリメント
    //   a = 30 / 2 = 15
    //
    //   lcd_list[15] = 3
    //   divisor_cnt[3] をインクリメント
    //   a = 15 / 3 = 5
    //
    //   lcd_list[5] = 5
    //   divisor_cnt[5] をインクリメント
    //   a = 5 / 5 = 1
    //
    // a=30 の場合、素因数である 2,3,5 を1回ずつカウントする
    set<int> s;
    while (a > 1) {
      int divisor = lcd_list.at(a);
      // 素因数はユニークに1度のみカウントする
      // 例えば a=24 は 2*2*2*3 であるが、2 を1回、3を1回カウントする
      if (divisor > 1 && !s.count(divisor)) {
        prime_factor_cnt.at(divisor)++;
        s.insert(divisor);
      }
      a = a / divisor;
    }
  }

  // 各素因数の登場回数が1回以下であれば、pairwise coprime
  //
  // ### pairwise coprime
  //
  // 素直に実装すると、計算量は以下となる。
  //
  //   全ての組合せ
  //     nC2 = (n * (n-1)) / (2*1)
  //   それぞれの組合せについて、ユークリッドの互除法で gcd を求める
  //     logA
  //   合わせると
  //     O(((n**2 / 2) - (n/2)) * logA)
  //     --> O(n**2 logA)
  //   n <= 10**6, A <= 10**6 より、10**9 を大きく超えるため時間内に計算が終わらない
  //
  // そのため、素因数に着目にする。
  //
  // それぞれの数について、共通の素因数が存在しない。
  // つまり、ある素因数が集合 {Ai} の高々1個の数にしか含まれていない。
  // そのような集合の場合、任意の2つの数の gcd が 1 となる。
  //
  //       Ai: 3 4 5
  //          -------
  //   素因数:   2
  //           3
  //               5
  //
  // ### setwise coprime
  // それぞれの数について、素因数が1ペア以上、共通する。
  // しかし、全ての数で共通する素因数は存在しない。
  // （全ての数で共通する素因数を P (> 1) とすると、gcd(A[0], A[1], ..., A[n-1]) = P > 1 となる）
  //
  // 以下の例では 2, 3, 5 いずれの素因数も3つの数の公約数とならず、gcd(6, 10, 15) = 1 となる。
  //
  //       Ai:  6 10 15
  //          ----------
  //   素因数:  2  2
  //            3     3
  //               5  5
  //
  bool is_pairwise = true;
  bool is_setwise = true;
  for (int i = 0; i <= lim; i++) {
    if (prime_factor_cnt.at(i) > 1) {
      is_pairwise = false;
    }
    if (prime_factor_cnt.at(i) == n) {
      is_setwise = false;
    }
  }

  if (is_pairwise) {
    cout << "pairwise coprime" << endl;
  } else if (is_setwise) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
  return 0;
}
