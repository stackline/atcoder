#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> d(100, 0);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    num--; // 0-indexed

    d.at(num)++;
  }

  int ans = 0;
  for (int i = 0; i < 100; i++) {
    if (d.at(i) > 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
