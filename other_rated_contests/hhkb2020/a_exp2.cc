#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  char s, t;
  cin >> s >> t;

  if (s == 'Y') {
    t = t - ('a' - 'A');
  }

  cout << t << endl;
  return 0;
}
