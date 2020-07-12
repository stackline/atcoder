#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  // "AC" の登場回数をカウントする
  vector<int> c(N, 0);
  for (int i = 0; i < N; i++) {
    string result = S.substr(i, 2);
    if (result == "AC") {
      c.at(i + 1)++;
    }
  }

  // 累積和にする
  vector<int> s(N + 1, 0);
  for (int i = 0; i < N; i++) {
    s.at(i + 1) = s.at(i) + c.at(i);
  }

  // for (int i = 0; i < N + 1; i++) {
  //   cout << i << " " << s.at(i) << endl;
  // }

  for (int i = 0; i < Q; i++) {
    int left, right;
    cin >> left >> right;
    // cin >> left >> right;
    cout << s.at(right) - s.at(left) << endl;
  }
  return 0;
}
