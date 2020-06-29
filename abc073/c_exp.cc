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

  int ptr = 0;
  int ans = 0;
  while (ptr < N) {
    int cc = A.at(ptr);
    int f = 0;

    // 自分自身を1枚目と計算する
    while (ptr < N && A.at(ptr) == cc) {
      f++;
      ptr++;
    }

    // 奇数回連続している場合は加算する
    int remainder = f % 2;
    ans += remainder;
  }

  cout << ans << endl;
  return 0;
}
