#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  long long max = 1000000000000000000LL;

  long long ans = 1;
  bool overflow_flag = false;
  bool zero_flag = false;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    long long result = ans * a;

    if (result < ans) {
      overflow_flag = true;
    }
    if (a == 0) {
      zero_flag = true;
    }

    ans = result;
  }

  if (zero_flag == false && (ans > max || overflow_flag == true)) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}

