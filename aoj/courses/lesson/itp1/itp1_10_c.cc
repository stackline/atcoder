#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    int n;
    cin >> n;

    if (n == 0) { break; }

    vector<double> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s.at(i);
    }

    // 平均値m
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += s.at(i);
    }
    double m = sum / n;

    // 分散a**2 = (Si - m)**2 の数列 / n
    double sum2 = 0;
    for (int i = 0; i < n; i++) {
      sum2 += (s.at(i) - m) * (s.at(i) - m);
    }
    double a_square = sum2 / n;

    // 標準偏差 = sqrt(分散)
    double standard_deviation = sqrt(a_square);

    printf("%.5f\n", standard_deviation);
  }
  return 0;
}
