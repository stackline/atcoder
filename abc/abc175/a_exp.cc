#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  bool p = (s.at(0) == 'R');
  bool q = (s.at(1) == 'R');
  bool r = (s.at(2) == 'R');

  if (p && q && r) {
    cout << 3 << endl;
  } else if ((p && q) || (q && r)) {
    cout << 2 << endl;
  } else if (p || q || r) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
