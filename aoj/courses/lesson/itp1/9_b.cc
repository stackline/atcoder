#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    string s;
    cin >> s;
    if (s == "-") { break; }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
      int h;
      cin >> h;

      string a = s.substr(0, h);
      string b = s.substr(h);

      s = b + a;
    }

    cout << s << endl;
  }

  return 0;
}
