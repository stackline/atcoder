#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    char c;
    scanf("%c", &c);

    // アルファベットかどうか
    if (isalpha(c)) {
      // 大文字かどうか
      if (isupper(c)) {
        cout << (char)tolower(c);
      } else {
        cout << (char)toupper(c);
      }
    } else {
      cout << c;
    }

    if (c == '\n') { break; }
  }
  return 0;
}
