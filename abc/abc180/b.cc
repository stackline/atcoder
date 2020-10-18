#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and
  // "scanf/printf".

  int n;
  cin >> n;

  vector<ll> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
  }

  ll a = 0;
  for (int i = 0; i < n; i++) {
    ll b = abs(x.at(i));
    a += b;
  }
  cout << a << endl;

  ll c = 0;
  for (int i = 0; i < n; i++) {
    ll f = abs(x.at(i));
    c += f * f;
  }
  printf("%.15f\n", sqrt(c));

  ll d = 0;
  for (int i = 0; i < n; i++) {
    ll e = abs(x.at(i));
    d = max(d, e);
  }
  cout << d << endl;

  return 0;
}
