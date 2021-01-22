#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m;
  cin >> n >> m;

  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());

  vector<int> x;
  // 青マスが2件以上存在する場合、青マスの間の白マスの数をカウントする
  for (int i = 1; i < m; i++) {
    int a_before = a.at(i - 1);
    int a_next = a.at(i);
    if (a_next - a_before - 1 > 0) {
      x.push_back(a_next - a_before - 1);
    }
  }

  // 青色マスが1件以上ある場合
  if (m > 0) {
    // 左端の白マスの数をカウントする
    // 例: マス1が白、マス2が青の場合
    // 2 - 1 = 1
    int left_side = a.at(0) - 1;
    if (left_side > 0) {
      x.push_back(left_side);
    }
    // 右端の白マスの数をカウントする
    // 例: n=5, m=2, (a1,a2)=(1,3) の場合
    // 5 - 3 = 2
    int right_side = n - a.at(m - 1);
    if (right_side > 0) {
      x.push_back(right_side);
    }
  }

  if ((int)x.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  int min_a = *min_element(x.begin(), x.end());

  int ans = 0;
  for (int i = 0; i < (int)x.size(); i++) {
    ans += x.at(i) / min_a;
    if (x.at(i) % min_a > 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
