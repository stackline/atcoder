#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int d, t, s;
  cin >> d >> t >> s;

  if (d <= t*s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
