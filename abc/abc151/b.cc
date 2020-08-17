#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // n科目
  // k点満点
  // n科目の平均点がm点以上
  int n, k, m;
  cin >> n >> k >> m;

  int sum = 0;
  for (int i = 0; i < n-1; i++) {
    int a;
    cin >> a;
    sum += a;
  }

  // 8+10+3+6=27
  // n=5, m=7, n*m=5,7=35
  for (int i = 0; i <= k; i++) {
    int n_sum = sum + i;
    if (n_sum >= m*n) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
