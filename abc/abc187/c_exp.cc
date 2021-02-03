#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  unordered_set<string> uset;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    uset.insert(s);
  }

  for (string s : uset) {
    if (uset.count("!" + s) >= 1) {
      cout << s << endl;
      return 0;
    }
  }

  cout << "satisfiable" << endl;
  return 0;
}
