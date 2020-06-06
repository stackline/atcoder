#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int alice = 0;
  int bob = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      alice += a.at(i);
    } else {
      bob += a.at(i);
    }
  }

  cout << (alice - bob) << endl;
  return 0;
}
