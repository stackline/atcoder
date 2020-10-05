#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 素因数分解
//
// ### 指数を計算する（例：n=24の場合）
//
// a*a <= 24 より max(a) = 4
// Math.sqrt(24) = 4.8989 からも 4
//
// 24 / 2 = 12 ... 0 2**1
// 12 / 2 =  6 ... 0 2**2
//  6 / 2 =  3 ... 0 2**3
//  3 / 2 =  1 ... 1
//  3 / 3 =  1 ... 0 3**1
//  1 / 3 =  0 ... 1
//  1 / 4 =  0 ... 1
//
// ### 指数を計算する（例：n=17の場合）
//
// a*a <= 17 より max(a) = 4
// Math.sqrt(17) = 4.1231 からも 4
//
// 17 / 2 = 0 ... 17
// 17 / 3 = 0 ... 17
// 17 / 4 = 0 ... 17
//
vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;

  for (ll a = 2; a*a <= n; a++) {
    if (n % a != 0) { continue; }

    ll exponent = 0;
    while (n % a == 0) {
      n = n / a;
      exponent++;
    }

    res.push_back(make_pair(a, exponent));
  }

  // n=17 など n が素数の場合はこちらで追加する
  if (n != 1) {
    res.push_back(make_pair(n, 1));
  }
  return res;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  vector<ll> v = {24, 17};
  for (int i = 0; i < (int)v.size(); i++) {
    ll n = v.at(i);
    vector<pair<ll, ll>> res = prime_factorize(n);

    cout << n << ":";
    for (pair<ll, ll> p : res) {
      for (int j = 0; j < p.second; j++) {
        cout << " " << p.first;
      }
    }
    cout << endl;
  }
  return 0;
}
