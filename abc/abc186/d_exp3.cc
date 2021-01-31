#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());

  // ### 二重和を一重和にする
  //
  // 昇順に sort すると、sigma は以下に変換できる。
  //
  //   sigma(|Ai - Aj|) = sigma(Aj - Ai)
  //    i j                i j
  //
  // sigma の差を分割する。
  //
  //   sigma(Aj - Ai) = sigma(Aj) - sigma(Ai)
  //    i j              i j         i j
  //
  // 入力例1の場合
  //
  //   sigma(Aj - Ai) は以下の和である。
  //    i j
  //
  //   (A1 - A0)
  //   (A2 - A0)
  //   (A2 - A1)
  //
  // 上記、入力例1の Aj, Ai の登場回数を基に、
  // 分割した2つの sigma を変換する。
  //
  //   sigma(Aj) = sigma(Aj * j)
  //    i j          j
  //
  //   sigma(Ai) = sigma(Ai * (N-i-1))
  //    i j          i
  //
  // 分割した sigma は以下と等しくなる。
  //
  //   sigma(Aj) - sigma(Ai) = sigma(Aj * j) - sigma(Ai * (N-i-1))
  //    i j         i j          j               i
  //
  //                         = sigma((Ak * k) - Ak * (N-k-1))
  //                             k
  //
  //                         = sigma(Ak * (k - (N-k-1)))
  //                             k
  //
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a.at(i) * (i - (n - i - 1));
  }
  cout << ans << endl;
  return 0;
}
