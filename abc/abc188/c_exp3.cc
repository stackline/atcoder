#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a.at(i);
  }

  auto max_elem_itr = max_element(a.begin(), a.end());
  int max_player = max_elem_itr - a.begin();
  int harf = (1 << (n - 1));
  auto start = (max_player >= harf) ? a.begin() : (a.begin() + harf);

  int second_player = max_element(start, start + harf) - a.begin();
  // 1-indexed に戻して出力
  int ans = second_player + 1;
  cout << ans << endl;
  return 0;
}
