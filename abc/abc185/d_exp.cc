#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: sort を利用しているため O(M log2(M))
//
// ### 例: N=9, M=4, A={2,4,6,8} の場合
// 白色のマスが連続している箇所は {1,3,5,7,9} であり、x=5 である。
//
// sort(a.begin(), a.end()) の計算回数
// 4 * log2(4) = 4 * 2 = 8
//
// for (int i = 0; i < m; i++) { の計算回数
// 4
//
// for (int i = 0; i < (int)x.size(); i++) { の計算回数
// 5
//
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
