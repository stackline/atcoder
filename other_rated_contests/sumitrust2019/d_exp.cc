#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string zero_padding(int n) {
  if (n == 0) { return "000"; }

  int n_copy = n;
  int digits = 0;
  while (n>0) {
    n = n / 10;
    digits++;
  }
  string s;
  for (int i = 0; i < (3-digits); i++) {
    s += '0';
  }
  return s+to_string(n_copy);
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    string p = zero_padding(i);
    size_t a = s.find_first_of(p.at(0));
    size_t b = s.find_first_of(p.at(1), a+1);
    size_t c = s.find_first_of(p.at(2), b+1);
    if (a != string::npos && b != string::npos && c != string::npos
        && a < b && b < c) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
