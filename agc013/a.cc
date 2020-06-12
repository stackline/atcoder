#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int ans = 0;
  for (int i = 0; i < N;) {
    // 数列の開始
    ans++;
    int from;

    // 単調非減少
    int j1;
    from = A.at(i);
    for (j1 = (i + 1); j1 < N; j1++) {
      int to = A.at(j1);
      if (from == to) {
        continue;
      } else if (from < to) {
        from = to;
        continue;
      } else {
        break;
      }
    }

    // 単調非増加
    int j2;
    from = A.at(i);
    for (j2 = (i + 1); j2 < N; j2++) {
      int to = A.at(j2);
      if (from == to) {
        continue;
      } else if (from > to) {
        from = to;
        continue;
      } else {
        break;
      }
    }

    // cout << "# loop start" << endl;
    // cout << "i:  " << i << endl;
    // cout << "j1: " << j1 << endl;
    // cout << "j2: " << j2 << endl;
    i = max(j1, j2);
  }

  cout << ans << endl;
  return 0;
}
