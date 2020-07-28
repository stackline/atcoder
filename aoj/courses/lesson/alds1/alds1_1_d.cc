#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R.at(i);
  }

  int maxv = -1000000000;
  int minv = R.at(0);
  // O(N)
  for (int i = 1; i < n; i++) {
    // 例: 5, 3, 1, 3, 4, 3
    //
    // i = 1 の時、R.at(1) - R.at(0) = 3 - 5 = -2
    // i = 2 の時、R.at(2) - R.at(1) = 1 - 3 = -2
    // i = 3 の時、R.at(3) - R.at(2) = 3 - 1 = 2
    // i = 4 の時、R.at(4) - R.at(2) = 4 - 1 = 3
    // i = 5 の時、R.at(5) - R.at(2) = 3 - 1 = 2
    maxv = max(maxv, R.at(i) - minv);
    minv = min(minv, R.at(i)); // 次のループで利用する、i-1 までの要素の中で最小の値を取得する
  }

  cout << maxv << endl;
  return 0;
}
