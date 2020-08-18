#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k, m;
  cin >> n >> k >> m;

  int sum = 0;
  for (int i = 0; i < n-1; i++) {
    int a;
    cin >> a;
    sum += a;
  }

  // n*m = 5*7 = 35
  // a[1] + ... a[n-1] = 27
  // minimum = 35 - 27 = 8
  int minimum = (n*m) - sum;

  // 必要点数が0点以下の場合
  // 最低点数は 0 点のため、0 を出力する
  if (minimum <= 0) {
    cout << 0 << endl;
  // 必要点数が1点以上、満点以下の場合
  // 最低限必要な点数が満点以内の場合は達成可能であるため、その点数を出力する
  } else if (minimum > 0 && minimum <= k) {
    cout << minimum << endl;
  // 最低限必要な点数が満点の点数を超えている場合、
  // 満点である k 点を取っても達成不可能であるため -1 を出力する
  } else if (minimum > k) {
    cout << -1 << endl;
  }

  return 0;
}
