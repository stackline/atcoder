#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> t(n);

int rec(int left, int right, int i) {
  // ベースケース
  if (i == n) {
    return max(left, right);
  }

  // 再帰ステップ
  // 左に置く場合
  int a = rec(left + t.at(i), right, i + 1);
  // 右に置く場合
  int b = rec(left, right + t.at(i), i + 1);

  return min(a, b);
}

int main() {
  cin >> n;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i);
  }

  int time = rec(0, 0, 0);
  cout << time << endl;
  return 0;
}
