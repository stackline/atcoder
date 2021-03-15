#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  double n;
  cin >> n;

  // ### 参考記事
  //
  // 和の期待値は期待値の和
  // https://manabitimes.jp/math/698
  //
  // ### 各回の操作の期待値
  //
  // 1回目の操作で、未訪問の頂点を訪れる確率
  //   (n-1) / n
  // 1回目の操作で、未訪問の頂点を訪れる期待値
  //   n / (n-1)
  //
  // 2回目の操作で、未訪問の頂点を訪れる確率
  //   (n-2) / n
  // 2回目の操作で、未訪問の頂点を訪れる期待値
  //   n / (n-2)
  //
  double ans = 0;
  double visited = 1;
  for (int i = 0; i < (n - 1); i++) {
    ans += n / (n - visited);
    visited++;
  }
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
