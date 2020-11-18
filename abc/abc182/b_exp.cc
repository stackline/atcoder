#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  // first:  GCD 度の値
  // second: first の GCD 度になる整数 k の値
  pair<int, int> ans(-1, -1);
  for (int k = 2; k <= 1000; k++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a.at(i) % k == 0) {
        cnt++;
      }
    }
    //
    // pair 型に対して max は以下の内容で大小を決定する。
    //
    // * 1つ目の要素が大きい方を大きいとみなす。
    // * 1つ目の要素が同じ値の場合、
    //   2つ目の要素が大きい方を大きいとみなす。
    //
    // 今回のケースでは、より GCD 度が大きい k が見つかった場合
    // pair を更新する。
    //
    // * ans.first = GCD 値が、より大きい値に更新される。
    // * ans.second = k が、ans.first の GCD 値を算出する k に更新される。
    //
    ans = max(ans, pair<int, int>(cnt, k));
  }
  cout << ans.second << endl;
  return 0;
}
