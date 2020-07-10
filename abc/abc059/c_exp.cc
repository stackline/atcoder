#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_even(int n) {
  return (n % 2 == 0);
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  ll sum;

  // 第1項を正とする場合
  ll p1_ans = 0;
  sum = 0;
  for (int i = 0; i < n; i++) {
    ll n = a.at(i);
    sum += n;

    // 添字が偶数番号の場合、和が正の数であることを期待する
    // 和が負の数の場合、正の数の最小値 +1 になるまで操作を繰り返す
    if (is_even(i)) {
      if (sum <= 0) {
        ll diff = 1 - sum;
        p1_ans += diff;
        sum += diff;
      }
    // 添字が奇数番号の場合、和が負の数であることを期待する
    // 和が正の数の場合、負の数の最小値 -1 になるまで操作を繰り返す
    } else {
      if (sum >= 0) {
        ll diff = sum - (-1);
        p1_ans += diff;
        sum -= diff;
      }
    }
  }

  // 第1項を負とする場合
  ll p2_ans = 0;
  sum = 0;
  for (int i = 0; i < n; i++) {
    ll n = a.at(i);
    sum += n;

    // 添字が偶数番号の場合、和が負の数であることを期待する
    // 和が正の数の場合、負の数の最小値 -1 になるまで操作を繰り返す
    if (is_even(i)) {
      if (sum >= 0) {
        ll diff = sum - (-1);
        p2_ans += diff;
        sum -= diff;
      }
    // 添字が奇数番号の場合、和が正の数であることを期待する
    // 和が負の数の場合、正の数の最小値 +1 になるまで操作を繰り返す
    } else {
      if (sum <= 0) {
        ll diff = 1 - sum;
        p2_ans += diff;
        sum += diff;
      }
    }
  }

  cout << min(p1_ans, p2_ans) << endl;
  return 0;
}
