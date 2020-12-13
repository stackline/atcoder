#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m, t;
  cin >> n >> m >> t;

  int n_max = n;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i) >> b.at(i);
  }

  int time = 0;
  for (int i = 0; i < m; i++) {
    int ax = a.at(i);
    int bx = b.at(i);

    // 外出〜カフェに行くまで、バッテリーが減少する
    n = n - (ax - time);
    if (n <= 0) {
      cout << "No" << endl;
      return 0;
    }

    // カフェにいる間、バッテリーが増加する
    // ただし、バッテリー容量以上は充電できない
    n = n + (bx - ax);
    n = min(n, n_max);

    time = bx;
  }

  // 最後にカフェを出た時間〜帰宅
  n = n - (t - time);
  if (n <= 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
