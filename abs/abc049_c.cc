#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool search(string &s, int pos) {
  // ベースケース
  if (pos == (int)s.size()) {
    return true;
  }

  // 再帰ステップ
  if ((int)s.find("dream", pos) == pos && search(s, pos + 5)) {
    return true;
  }
  if ((int)s.find("dreamer", pos) == pos && search(s, pos + 7)) {
    return true;
  }
  if ((int)s.find("erase", pos) == pos && search(s, pos + 5)) {
    return true;
  }
  if ((int)s.find("eraser", pos) == pos && search(s, pos + 6)) {
    return true;
  }

  return false;
}

int main() {
  string S;
  cin >> S;

  bool enabling = search(S, 0);
  cout << (enabling ? "YES" : "NO") << endl;
  return 0;
}
