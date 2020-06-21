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
  sort(A.begin(), A.end());

  int a_max = A.at(N - 1);
  vector<int> range(a_max + 1, 0);

  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    range.at(a)++;

    // 2つ以上の約数が存在する場合
    if (range.at(a) >= 2) {
      continue;
    }

    for (int j = a * 2; j <= a_max; j = j + a) {
      range.at(j)++;
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    if (range.at(a) == 1) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
