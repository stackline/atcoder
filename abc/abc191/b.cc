#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, x;
  cin >> n >> x;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a != x) {
      v.push_back(a);
    }
  }
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v.at(i);
    if (i != (int)v.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
