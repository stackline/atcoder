#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++) {
    cin >> p.at(i) >> c.at(i);
  }

  int ans = 10 * 100;
  for (int mask = 0; mask < (1 << D); mask++) {
    int s = 0;
    int num = 0;
    int rest_max = -1;

    for (int i = 0; i < D; i++) {
      if (mask >> i & 1) {
        s += 100 * (i + 1) * p.at(i) + c.at(i);
        num += p.at(i);
      } else {
        rest_max = i;
      }
    }

    if (s < G) {
      int s1 = 100 * (rest_max + 1);
      int need = 0;
      int reminder = (G - s) % s1;
      if (reminder == 0) {
        need = (G - s) / s1;
      } else {
        need = (G - s) / s1 + 1;
      }

      if (need >= p.at(rest_max)) {
        continue;
      }
      num += need;
    }

    ans = min(ans, num);
  }

  cout << ans << endl;
  return 0;
}
