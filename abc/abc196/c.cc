#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  // 桁数を数える
  ll digit = 0;
  ll nx = n;
  while (nx > 0) {
    digit++;
    nx = nx / 10;
  }

  ll ans = 0;
  for (int i = 1; i <= (digit - 1); i++) {
    if (i % 2 == 0) {
      ll base = 1;
      for (int j = 0; j < ((i / 2) - 1); j++) {
        base *= 10;
      }
      ans += base * 9;
    }
  }

  if (digit % 2 == 1) {
    // 桁数が奇数の場合
    cout << ans << endl;
    return 0;
  } else {
    // 桁数が偶数の場合
    string s = to_string(n);
    string l = s.substr(0, digit / 2);
    string r = s.substr(digit / 2);
    ll lnum = stoll(l);
    ll rnum = stoll(r);

    ll base = 1;
    for (int i = 0; i < ((digit / 2) - 1); i++) {
      base *= 10;
    }

    for (int i = base; i <= lnum; i++) {
      if (i < lnum) {
        ans++;
      } else {
        if (i <= rnum) {
          ans++;
        }
      }
    }

    cout << ans << endl;
    return 0;
  }
  return 0;
}
