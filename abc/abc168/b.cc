#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;

  int s_len = (int) s.size();
  if (s_len <= k) {
    cout << s << endl;
  } else {
    string s2 = s.substr(0, k);
    cout << s2 << "..." << endl;
  }

  return 0;
}
