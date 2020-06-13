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

  bool increasing = false;
  bool decreasing = false;
  int ans = 1;
  for (int i = 1; i < N; i++) {
    if (A.at(i - 1) < A.at(i)) {
      increasing = true;
    }
    if (A.at(i - 1) > A.at(i)) {
      decreasing = true;
    }

    // 「増加のあとに減少」あるいは「減少のあとに増加」を確認したタイミングで
    // 数式の分割が発生する
    if (increasing && decreasing) {
      ans++;
      increasing = false;
      decreasing = false;
    }
  }

  cout << ans << endl;
  return 0;
}
