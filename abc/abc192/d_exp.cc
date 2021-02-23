#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string x;
  ll m;
  cin >> x >> m;

  // コーナーケース
  if ((int)x.size() == 1) {
    if (stoi(x) <= m) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  // x に含まれる最も大きい数字 d
  int d = 0;
  for (char c : x) {
    d = max(d, c - '0');
  }

  // 二分探索
  ll ac = d;     // 下限
  ll wa = m + 1; // 上限

  while (wa - ac > 1) {
    // wj = waiting judge
    ll wj = (ac + wa) / 2;

    ll v = 0;
    for (char c : x) {
      // v * wj > m を超えてはいけない
      // 両辺に wj を掛ける
      //
      //   v > (m / wj)
      if (v > (m / wj)) {
        // (v > m) を満たすように、v に適当な値を代入する。
        v = m + 1;
      } else {
        // 文字列 x を reverse する必要がない。
        //
        //   1桁目 --> 0 * wj + (c - '0')
        //   2桁目 --> (c - '0') * wj + (c - '0')
        //   3桁目 --> (c - '0') * wj^2 + (c - '0') * wj^1 + (c - '0')
        v = v * wj + (c - '0');
      }
    }
    if (v <= m) {
      ac = wj;
    } else {
      wa = wj;
    }
  }

  cout << ac - d << endl;
  return 0;
}
