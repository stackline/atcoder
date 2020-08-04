#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
  }

  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y.at(i);
  }

  // p = 1〜3 の場合
  vector<int> p_list = {1, 2, 3};
  for (int i = 0; i < (int)p_list.size(); i++) {
    int p = p_list.at(i);

    double summation = 0;
    for (int i = 0; i < n; i++) {
      int dif = x.at(i) - y.at(i);
      // 絶対値をとる
      if (dif < 0) { dif = dif * -1; }
      dif = pow(dif, p);
      summation += dif;
    }

    // cout << "summation: " << summation << endl;

    double root = pow(summation, (1.0 / p));
    printf("%.6f\n", root);
  }

  // p = 無限の場合
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int dif = x.at(i) - y.at(i);
    if (dif < 0) { dif = dif * -1; }
    ans = max(ans, dif);
  }
  printf("%.6f\n", (double)ans);
  return 0;
}
