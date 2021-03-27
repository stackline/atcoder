#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  string s = to_string(n);
  int digit = s.size();

  if (digit == 1) {
    cout << 0 << endl;
    return 0;
  }

  // 正規化する
  ll num;
  if (digit % 2 == 1) {
    ll base = 1;
    for (int i = 0; i < (digit - 1); i++) {
      base *= 10;
    }
    num = base - 1;
  } else {
    num = n;
  }

  string s2 = to_string(num);
  string left = s2.substr(0, digit / 2);
  string right = s2.substr(digit / 2);

  ll ans = 0;
  ans += (stoll(left) - 1);
  if (stoll(left) <= stoll(right)) {
    ans++;
  }
  cout << ans << endl;
}
