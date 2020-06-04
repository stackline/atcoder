#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    int count = 0;
    while (num % 2 == 0) {
      num = num / 2;
      count++;
    }

    a.at(i) = count;
  }

  int ans = a.at(0);
  for (int i = 1; i < N; ++i) {
    ans = min(ans, a.at(i));
  }

  cout << ans << endl;
  return 0;
}
