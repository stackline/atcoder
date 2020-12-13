#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i);
  }
  // 最後に blue でフタをする
  a.push_back(n + 1);

  sort(a.begin(), a.end());

  vector<int> blocks;
  int index = 0;
  int min_len = n;
  for (int i = 0; i < (int)a.size(); i++) {
    int ax = a.at(i);
    int len = ax - index - 1;
    index = ax;
    // cout << "ax: " << ax << ", len: " << len << ", index: " << index << endl;

    if (len <= 0) {
      continue;
    }

    blocks.push_back(len);
    min_len = min(min_len, len);
  }

  int ans = 0;
  for (int i = 0; i < (int)blocks.size(); i++) {
    int block = blocks.at(i);
    // cout << "block:   " << block << endl;
    // cout << "min_len: " << min_len << endl;

    ans += block / min_len;
    if (block % min_len != 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
