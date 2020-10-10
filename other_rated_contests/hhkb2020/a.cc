#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  char s, t;
  cin >> s >> t;

  if (s == 'Y') {
    cout << (char)toupper(t) << endl;
  } else {
    cout << t << endl;
  }
  return 0;
}
