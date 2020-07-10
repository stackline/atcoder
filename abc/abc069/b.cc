#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int size = (int)s.size();
  string ans = s.at(0) + to_string(size - 2) + s.at(size - 1);
  cout << ans << endl;
  return 0;
}
