#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, x;
  cin >> N >> x;

  ll sum = 0;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }

  int ans = 0;
  if (x == sum) {
    ans = N;
  } else if (x > sum) {
    ans = N - 1;
  } else { // x < sum
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
      int num = a.at(i);
      if (x < num) {
        break;
      }
      x -= num;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
