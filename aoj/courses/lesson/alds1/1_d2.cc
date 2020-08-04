#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int maxv = -1000000000;
  int minv;
  cin >> minv;
  // O(N)
  for (int i = 1; i < n; i++) {
    int r;
    cin >> r;
    maxv = max(maxv, r - minv);
    minv = min(minv, r); // 次のループで利用する、i-1 までの要素の中で最小の値を取得する
  }

  cout << maxv << endl;
  return 0;
}
