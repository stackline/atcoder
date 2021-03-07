#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MaxA = 200;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  vector<int> cnt(MaxA * 2 + 1);
  ll ans = 0;
  //
  // 例: i = 2 の時、i = 0, i = 1 の時の値を cnt でカウントしている。
  // cnt で A[0] 〜 A[i-1] の値をカウントしている。
  //
  // Ai = "i=2の値" である。
  // Aj = 毎回 -200 〜 200 を探索する。
  //
  // ここで、A[0] 〜 A[i-1] までの cnt を考慮する。
  // cnt が 0 の場合、対象の値は i= 0 〜 i-1 の間で一度も登場していない数のため、
  // 加算の対象外である。
  //
  // カーソル位置の値を Ai とする。
  // カーソル位置手前までに登場した値を cnt で記録する。
  // (Ai - Aj)**2 を計算する際に、Aj に入りうる値 -200 〜 200 を毎回全探索する。
  // ここで cnt で i-1 までに登場した値の数を掛けることで、値の登場回数に応じて、
  // (Ai - Aj)**2 の数を加算している。
  //
  // ### 入力例1の場合
  //
  // n = 3
  // A = {2,8,4}
  //
  // i = 1 の場合
  //   cnt[202] = 1 である。
  //
  //   x = 8 - 2 = 6
  //   6 * 6 * 1 = 36 を ans に加算する。
  //
  // i = 2 の場合
  //   cnt[202] = 1, cnt[208] = 1 である。
  //
  //   x = 4 - 2 = 2
  //   2 * 2 * 1 = 4 を ans に加算する。
  //
  //   x = 4 - 8 = -4
  //   -4 * -4 * 1 = 16 を ans に加算する。
  //
  // 合計は 36 + 4 + 16 = 56 である。
  //
  // ### 計算量
  //
  // n <= 3 * 10**5 より、ループ数は最大で 3 * 10**5 * 401
  //
  //   10**8 < 120300000 < 10**9
  //
  for (int i = 0; i < n; i++) {
    // Ai 側は全探索する。Aj 側の計算量を減らす。
    for (int aj = -MaxA; aj <= MaxA; aj++) {
      int c = cnt.at(MaxA + aj);
      // x**2 = (Ai - Aj)**2
      int x = a.at(i) - aj;
      ans += (ll)x * x * c;
    }

    int idx = a.at(i) + MaxA;
    cnt.at(idx)++;
  }

  cout << ans << endl;
  return 0;
}
