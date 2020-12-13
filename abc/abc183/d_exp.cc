#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### 計算量
// データ受け取り: N
// sort:           NlogN
// シミュレート:   2N
//
// O(N + NlogN + 2N)
// = O(3N + NlogN)
//
// これより計算量は O(NlogN)
//
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, w;
  cin >> n >> w;

  vector<pair<int, int>> event;

  // ### 入力例 1 の場合
  //
  // event[0] = ( 1,  5)
  // event[1] = ( 3, -5)
  // event[2] = ( 2,  4)
  // event[3] = ( 4, -4)
  // event[4] = ( 3,  6)
  // event[5] = (10, -6)
  // event[6] = ( 2,  1)
  // event[7] = ( 4, -1)
  //
  for (int i = 0; i < n; i++) {
    int s, t, p;
    cin >> s >> t >> p;

    event.push_back(make_pair(s, p));
    event.push_back(make_pair(t, -p));
  }

  // ( 1,  5)
  // ( 2,  1)
  // ( 2,  4)
  // ( 3, -5)
  // ( 3,  6)
  // ( 4, -4)
  // ( 4, -1)
  // (10, -6)
  sort(event.begin(), event.end());

  // シミュレート
  ll crr = 0;
  for (auto [time, value] : event) {
    crr += value;
    if (crr > w) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
