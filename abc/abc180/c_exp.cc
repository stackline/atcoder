#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// endl: line break + buffer flush
// '\n': line break
// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
//
// 計算量: O(sqrt(n) + k * log(k))
//
//   k は n の約数の個数
//   要素数を N とした場合、set.insert の1回あたりの計算量は O(log(N)) である。
//   これらより、k 回 set.insert を行うため k * log(k) となる。
//
// 計算量の例
//
//   n=720 の場合（約数30個）
//     Math.sqrt(720) =  26.832815729997478
//     30 * log(30)   = 102.03592144986466
//   n=10**12 の場合（約数169個）
//     Math.sqrt(10**12) = 1000000.0
//     169 * log(169)    =     866.9528828219994
//
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Do not use both "cin/cout" and "scanf/printf" at the same time.

  ll n;
  cin >> n;

  set<ll> divisors;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.insert(i);
      divisors.insert(n / i);
    }
  }

  for (ll divisor : divisors) {
    cout << divisor << endl;
  }
  return 0;
}
