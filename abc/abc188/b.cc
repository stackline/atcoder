#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### 内積について
// https://www.studyplus.jp/467
//
// ->a = ベクトルa
// ->b = ベクトルb
//
// |->a| = ベクトルaの長さ
// |->b| = ベクトルbの長さ
//
// ->a * ->b = ->aと->bの内積
//           = |->a| * |->bが->aに作る影の長さ|
//
// 内積の性質を利用すると、2つのベクトルの角度 cos0 を求めやすい。
// 3次元ベクトルも2次元ベクトルと同様の性質を持つ。
// 3Dゲーム等、3次元空間の計算で利用するらしい。
//
//
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  ll ans = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
  }

  for (int i = 0; i < n; i++) {
    ans += a.at(i) * b.at(i);
  }

  if (ans == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
