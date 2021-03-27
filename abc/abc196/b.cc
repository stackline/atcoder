#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string x;
  cin >> x;

  for (int i = 0; i < (int)x.size(); i++) {
    char c = x.at(i);
    if (c == '.') {
      cout << endl;
      return 0;
    }
    cout << c;
  }
  cout << endl;
  return 0;
}
