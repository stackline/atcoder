#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool imos(ll n, ll w, vector<ll> s, vector<ll> t, vector<ll> p) {
  const ll UPPER_LIMIT = 2e5 + 2;
  vector<ll> table(UPPER_LIMIT);

  // 記録
  for (int i = 0; i < n; i++) {
    table.at(s.at(i)) += p.at(i);
    table.at(t.at(i)) -= p.at(i);
  }

  // シミュレート
  for (int i = 1; i < UPPER_LIMIT; i++) {
    table.at(i) = table.at(i) + table.at(i - 1);
  }

  // 条件を満たすか調べる
  for (int i = 0; i < UPPER_LIMIT; i++) {
    if (table.at(i) > w) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  ll w;
  cin >> n >> w;
  vector<ll> s(n);
  vector<ll> t(n);
  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i) >> t.at(i) >> p.at(i);
  }

  bool can = imos(n, w, s, t, p);
  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
