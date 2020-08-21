#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < (int) s.size(); i++) {
    char c = s.at(i) + n;
    if (c > 'Z') {
      c = c - ('Z' - 'A' + 1);
    }
    cout << c;
  }
  cout << endl;
  return 0;
}
