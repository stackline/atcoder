#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  // k=2
  //   0個消す
  //     3 + 5 = 8 (ng)
  //   1個消す
  //     3 (ok)
  //     5 (ng)
  // k=7
  //   0個消す (7C0 = 1)
  //   1個消す (7C1 = 7)
  //   2個消す (7C2 = 21)
  //   3個消す (7C3 = 7*6*5/3*2*1 = 35)
  //   4個消す (7C4 = 7*6*5*4/4*3*2*1 = 35)
  //   ...
  //   6個消す (7C6 = 7)
  string s;
  cin >> s;

  // 0: 00
  // 1: 01
  // 2: 10
  // 3: 11
  int ans = -1;
  for (int tmp = 0; tmp < (1 << (int)s.size()); tmp++) {
    bitset<18> bs(tmp);
    // bs = "00" つまり、全て消すパターンはスキップする
    if (bs.count() == 0) {
      continue;
    }

    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      // bit が立っている場合は加算する
      if (bs.test(i)) {
        sum += s.at(i) - '0';
      }
    }

    // 3の倍数かどうか判定
    if (sum % 3 == 0) {
      // 消した桁数
      int cnt = s.size() - bs.count();
      if (ans == -1) {
        ans = cnt;
      } else {
        ans = min(ans, cnt);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
