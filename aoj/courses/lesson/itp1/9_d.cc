#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string str;
  cin >> str;

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    string command;
    int a, b;
    cin >> command >> a >> b;

    if (command == "print") {
      cout << str.substr(a, (b - a + 1)) << endl;
    } else if (command == "reverse") {
      // 2文字目から4文字目の場合 (abcdef)
      // * 0 から 2 文字 (ab)
      // * 2 から 3 文字 (cde)
      // * 4 文字目から最後まで (ef)
      string p1 = str.substr(0, a);
      string p2 = str.substr(a, (b - a + 1));
      reverse(p2.begin(), p2.end());
      string p3 = str.substr(b + 1);

      str = p1 + p2 + p3;
    } else if (command == "replace") {
      string p;
      cin >> p;
      str.replace(a, (b - a + 1), p);
    }
  }

  return 0;
}
