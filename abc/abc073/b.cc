#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    sum += (r - l) + 1;
  }
  cout << sum << endl;
  return 0;
}
