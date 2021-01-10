#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> solve(vector<pair<int, int>> a) {
  int a_size = a.size();
  // ベースケース
  if (a_size == 2) {
    pair<int, int> x = a.at(0);
    pair<int, int> y = a.at(1);
    if (x.second < y.second) {
      return x;
    }
    return y;
  }
  // 再帰ステップ
  vector<pair<int, int>> b;
  for (int i = 0; i < (a_size / 2); i++) {
    // i=0 0,1
    // i=1 2,3
    // i=2 4,5
    pair<int, int> x = a.at(i * 2);
    pair<int, int> y = a.at(i * 2 + 1);
    // 大きい方を残す
    // cout << "##### debug" << endl;
    // printf("x.first: %d, x.second: %d\n", x.first, x.second);
    // printf("y.first: %d, y.second: %d\n", y.first, y.second);
    if (x.second > y.second) {
      b.push_back(x);
    } else {
      b.push_back(y);
    }
  }
  return solve(b);
}

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  int pow = 1;
  for (int i = 0; i < n; i++) {
    pow *= 2;
  }

  vector<pair<int, int>> a(pow);
  for (int i = 0; i < pow; i++) {
    int x;
    cin >> x;
    a.at(i) = make_pair(i + 1, x);
  }

  cout << solve(a).first << endl;
  return 0;
}
