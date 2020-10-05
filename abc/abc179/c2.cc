#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

  if (n != 1) {
    res.push_back(make_pair(n, 1));
  }
  return res;
}

ll combination(ll n, ll k) {
  ll num = 1;
  for (ll i = 1; i <= k; i++) {
    num = num * (n - i + 1) / i;
  }
  return num;
}

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;

  // ### 条件
  // 正整数の組のため、A >= 1 && B >= 1 && C >= 1
  // A=1 && B=1 の場合、C = N - A * B = N - 1 となる。
  //   これが C の取りうる最大値である。
  //
  // C の値を決定すると、A*B の値が決定する。
  // A*B の値を素因数分解した後、A と B のどちらに分配するかの場合の数を数える。
  //
  // ### 例えば n=13、c=1 の場合
  //
  // a*b = 13 - 1 = 12
  // 12 を素因数分解すると (2, 2, 3) となる。　
  // 各素数とその件数は以下となる。
  //
  //   2: 2件
  //   3: 1件
  //
  // 各素数を a, b どちらに何件分配するかという、重複組み合わせの数を数える。
  //
  //   ### 素数2について
  //   2つのボールを1つの仕切りで区切る重複組み合わせの数と考える。
  //   仕切りの左を A に分配、仕切りの右を B に分配する。
  //   3C1 = 3通りである。
  //
  //     | o o
  //     o | o
  //     o o |
  //
  //   ### 素数3について
  //   1つのボールを1つの仕切りで区切る重複組み合わせの数と考える。
  //   分配の考え方は素数2と同様。
  //   2C1 = 2通りである。
  //
  //     | o
  //     o |
  //
  //   素数2の分配方法のパターン数と素数3の分配方法のパターン数をかけて、
  //   全ての分配方法の数を求める。
  //
  //     3 * 2 = 6通り
  //
  // c=2 〜 c=n-1 についても、同様の方法で (A, B, C) の組を求める。
  //
  ll ans = 0;
  for (int c = 1; c < n; c++) {
    int a_times_b = n - c;
    vector<pair<ll, ll>> v = prime_factorize(a_times_b);

    ll cnt = 1;
    for (pair<ll, ll> p : v) {
      cnt = cnt * combination(p.second + 1, 1);
    }
    ans += cnt;
  }

  cout << ans << endl;
  return 0;
}
