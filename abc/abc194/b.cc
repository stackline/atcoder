#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(n)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);

  // 同じ人がA,B両方取り組む時の最小の値
  ll c = 10000000000;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i) >> b.at(i);
    c = min(c, (a.at(i) + b.at(i)));
  }

  // 異なる人がA,Bを取り組む時の最小値
  auto b_copy = b;
  sort(b_copy.begin(), b_copy.end());

  bool dup = false;
  if (b_copy.at(0) == b_copy.at(1)) {
    dup = true;
  }

  // cout << (dup ? "true" : "false") << endl;

  ll d = 10000000000;
  for (int i = 0; i < n; i++) {
    ll a_fin = a.at(i);
    ll bx = b.at(i);

    ll b_fin;
    if (dup == true) {
      b_fin = b_copy.at(0);
    } else {
      if (bx == b_copy.at(0)) {
        b_fin = b_copy.at(1);
      } else {
        b_fin = b_copy.at(0);
      }
    }

    ll min_fin = max(a_fin, b_fin);
    d = min(d, min_fin);
  }

  if (c < d) {
    cout << c << endl;
  } else {
    cout << d << endl;
  }

  return 0;
}
