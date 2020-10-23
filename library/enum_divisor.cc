#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 約数列挙
//
// ### 計算量
// O(sqrt(n) + k * log(k))
// k は約数の数
//
// ### NOTE
// データ構造として set を使うことによって、
// 引数 n が 1, 4, 9, 16... という平方数の場合に、
// 平方根が二重に登録されない。
//
// 例えば n = 16, i = 4 の場合
//
//   s.insert(i)     // 4 を追加
//   s.insert(n / i) // 16 / 4 = 4 を追加
//
// set の特性により2回目の set.insert(4) は無視される。
// また、ループでデータを取り出す場合は、小さいものから取り出される。
//
set<ll> enum_divisors(ll n) {
  set<ll> s;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  return s;
}

int main() {
  ll n = 12;
  set<ll> s = enum_divisors(n);

  // 1 2 3 4 6 12
  for (ll i : s) {
    cout << i << '\n';
  }
  return 0;
}
