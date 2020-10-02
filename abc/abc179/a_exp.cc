#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  string s;
  cin >> s;

  int len = s.length();

  if (s.at(len-1) == 's') {
    s += "es";
  } else {
    s += "s";
  }

  cout << s << endl;
  return 0;
}
