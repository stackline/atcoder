#include <bits/stdc++.h>
using namespace std;

int calc(int &g, int min_count, vector<int> p, vector<int> c, int sum, int count, int i) {
  // ベースケース
  // 0 + (0 + 1) * 100
  // = 0 + 1 * 100
  // = 100
  sum += (i + 1) * 100;
  // 3 - 1
  // = 2
  p[i]--;
  count++;
  if (p[i] == 0) {
    sum += c[i];
  }

  if (sum >= g) {
    return count;
  }

  // 再帰ステップ
  for (int j = 0; j < (int) p.size(); j++) {
    if (p[j] > 0) {
      int calculated = calc(g, min_count, p, c, sum, count, j);
      min_count = min(min_count, calculated);
    }
  }

  return min_count;
}

int main() {
  int d, g;
  cin >> d >> g;
  vector<int> p(d);
  vector<int> c(d);
  for (int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
  }

  int min_count = 0;
  for (int i = 0; i < d; i++) {
    min_count += p[i];
  }

  for (int i = 0; i < d; i++) {
    int calculated = calc(g, min_count, p, c, 0, 0, i);
    min_count = min(min_count, calculated);
  }

  cout << min_count << endl;
  return 0;
}
