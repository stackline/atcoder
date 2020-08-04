#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string W;
  cin >> W;

  int counter = 0;
  while (1) {
    string s;
    cin >> s;

    if (s == "END_OF_TEXT") { break; }

    // 大文字小文字を区別しないように、小文字に寄せる
    for (int i = 0; i < (int)s.size(); i++) {
      char c = s.at(i);
      if (isalpha(c) && isupper(c)) {
        s.at(i) = tolower(c);
      }
    }

    if (s == W) { counter++; }
  }
  cout << counter << endl;
  return 0;
}
