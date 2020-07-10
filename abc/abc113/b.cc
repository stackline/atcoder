#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; // <= 1000
  int T; // <= 50
  int A; // -60 <= A <= 50
  cin >> N >> T >> A;

  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }

  int ans = 0;
  double min_diff = abs((double)A - ((double)T - (double)h.at(0) * 0.006));
  for (int i = 1; i < N; i++) {
    double diff = abs((double)A - ((double)T - (double)h.at(i) * 0.006));
    if (diff < min_diff) {
      min_diff = diff;
      ans = i;
    }
  }

  cout << (ans + 1) << endl;
  return 0;
}
