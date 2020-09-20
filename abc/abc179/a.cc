#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  string s;
  cin >> s;

  int s_size = (int) s.size();
  cout << s;
  if (s.at(s_size-1) == 's') {
    cout << "es";
  } else {
    cout << "s";
  }
  cout << endl;

  return 0;
}
