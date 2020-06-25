#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int max_num = max(max(A, B), C);
  int remaining = (A + B + C) - max_num;
  int diff_num = (max_num * 2) - remaining;

  int ans = 0;
  // 差が偶数の場合
  if (diff_num % 2 == 0) {
    ans = diff_num / 2;
  // 差が奇数の場合
  } else {
    max_num += 2;
    remaining += 1;
    diff_num = (max_num * 2) - remaining;
    ans = diff_num / 2;
  }

  cout << ans << endl;
  return 0;
}
