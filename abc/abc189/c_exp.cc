#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: 最大長方形のDP / O(N)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  // stack で長方形の面積を計算するため、みかんの数が 0 個の皿を最後に追加する。
  a.push_back(0);

  // pair<int, int> = <みかんの数、開始位置>
  stack<pair<int, int>> sv;

  int ans = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    // 次の皿が増加の場合
    if (sv.size() == 0 || sv.top().first < a.at(i)) {
      sv.push(make_pair(a.at(i), i));
    }
    // 次の皿が減少の場合
    else if (sv.top().first > a.at(i)) {
      int from_position = 0;
      while (sv.size() > 0) {
        pair<int, int> p = sv.top();
        if (p.first >= a.at(i)) {
          sv.pop();
          from_position = p.second;
          int area = (i - p.second) * p.first;
          ans = max(ans, area);
        } else {
          break;
        }
      }
      sv.push(make_pair(a.at(i), from_position));
    }
  }

  cout << ans << endl;
  return 0;
}
