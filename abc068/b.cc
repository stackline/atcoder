#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 1;
  int max_count = 0;
  for (int i = 1; i <= N; i++) {
    int count = 0;
    int num = i;
    while (num % 2 == 0) {
      num = num / 2;
      count++;
    }

    if (count > max_count) {
      max_count = count;
      ans = i;
    }
  }

  cout << ans << endl;
  return 0;
}
