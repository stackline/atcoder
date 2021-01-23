#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;
  if (s.at(0) == s.at(1) && s.at(1) == s.at(2)) {
    cout << "Won" << endl;
  } else {
    cout << "Lost" << endl;
  }
  return 0;
}
