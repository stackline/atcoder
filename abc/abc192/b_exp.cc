#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  bool is_unreadable = true;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);
    if ((i + 1) % 2 == 1) { // 奇数番目
      if (!islower(c)) {
        is_unreadable = false;
      }
    } else { // 偶数番目
      if (!isupper(c)) {
        is_unreadable = false;
      }
    }
  }

  if (is_unreadable) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
