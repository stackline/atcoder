#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int a = 0;
  int b = 0;
  int ab = 0;

  // 必要なピザの枚数を比較して、A・Bの両方で最低限必要な枚数を算出
  int n = min(X, Y);

  // ABを2枚購入する方が、A・Bを1枚ずつ購入するより安い場合
  if ((C * 2) < (A + B)) {
    ab = n * 2;
  // ABを2枚購入する方が、A・Bを1枚ずつ購入するより高い場合
  } else {
    a = n;
    b = n;
  }

  // 残りの必要なピザの枚数
  int x_rest = X - n;
  int y_rest = Y - n;

  // 残りのAピザを、Aピザ1枚 or ABピザ2枚の安い方で補填する
  if ((C * 2) < A) {
    ab += x_rest * 2;
  } else {
    a += x_rest;
  }

  // 残りのBピザを、Bピザ1枚 or ABピザ2枚の安い方で補填する
  if ((C * 2) < B) {
    ab += y_rest * 2;
  } else {
    b += y_rest;
  }

  cout << (A * a + B * b + C * ab) << endl;
  return 0;
}
