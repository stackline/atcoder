#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<vector<double>>>
    dp(101, vector<vector<double>>(101, vector<double>(101, 0)));

// メモ化再帰
double f(int a, int b, int c) {
  // ベースケース
  if (a == 100 || b == 100 || c == 100) {
    return 0;
  }
  if (dp.at(a).at(b).at(c) > 0) {
    return dp.at(a).at(b).at(c);
  }

  // 金貨を引いた時の操作回数の期待値 ×金貨を引く確率
  double x = (f(a + 1, b, c) + 1) * a / (a + b + c);
  double y = (f(a, b + 1, c) + 1) * b / (a + b + c);
  double z = (f(a, b, c + 1) + 1) * c / (a + b + c);
  double ans = x + y + z;
  dp.at(a).at(b).at(c) = ans;

  return ans;
}

// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(9);
  cout << f(a, b, c) << endl;
  return 0;
}
