#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> divide = { "dream", "dreamer", "erase", "eraser" };

int main() {
  string S;
  cin >> S;

  // 文字列を後ろからマッチングさせていく
  reverse(S.begin(), S.end());
  for (int i = 0; i < (int)divide.size(); i++) {
    reverse(divide.at(i).begin(), divide.at(i).end());
  }

  bool can = true;
  for (int i = 0; i < (int)S.size();) {
    bool can2 = false;
    for (int j = 0; j < (int)divide.size(); j++) {
      string d = divide.at(j);
      if (S.substr(i, (int)d.size()) == d) {
        can2 = true;
        i += (int)d.size();
      }
    }
    if (!can2) {
      can = false;
      break;
    }
  }

  cout << (can ? "YES" : "NO") << endl;
  return 0;
}
