#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  vector<int> waters;
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= 30; j++) {
      int water = 100 * A * i + 100 * B * j;
      if (water <= F) {
        waters.push_back(water);
      }
    }
  }

  vector<int> sugars;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      int sugar = C * i + D * j;
      if (sugar <= F) {
        sugars.push_back(sugar);
      }
    }
  }

  int ans_w = 0;
  int ans_s = 0;
  double percent = -1.0;

  for (auto w : waters) {
    for (auto s : sugars) {
      int total = w + s;
      if (total > F) {
        continue;
      }

      int sugar_upper_limit = (w / 100) * E;

      double p = double(100 * s) / double(w + s);
      if (s <= sugar_upper_limit && p > percent) {
        ans_w = w;
        ans_s = s;
        percent = p;
      }
    }
  }

  cout << (ans_w + ans_s) << " " << ans_s << endl;
  return 0;
}
