#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A;
  string B;
  cin >> A >> B;

  int pos = B.find_first_of('.');
  string s = B.substr(0, pos) + B.substr(pos + 1);
  ll ans = (A * stoll(s)) / 100;
  cout << ans << endl;
  return 0;
}
