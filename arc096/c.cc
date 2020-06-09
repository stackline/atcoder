#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int a = 0;
  int b = 0;
  int ab = 0;

  // ABピザを2枚購入する方が、Aピザ・Bピザを1枚ずつ購入するより安い場合
  if ((C * 2) < (A + B)) {
    // 買える分だけABピザを買う
    int n = min(X, Y);
    ab = n * 2;

    int x_rest = X - n;
    int y_rest = Y - n;

    // Aピザ1枚 or ABピザ2枚の安い方で購入する
    if ((C * 2) < A) {
      ab += x_rest * 2;
    } else {
      a += x_rest;
    }

    // Bピザ1枚 or ABピザ2枚の安い方で購入する
    if ((C * 2) < B) {
      ab += y_rest * 2;
    } else {
      b += y_rest;
    }
  // ABピザを2枚購入した方が高い場合
  // Aピザ・Bピザを1枚ずつ購入する
  } else {
    // 買える分だけAピザ・Bピザを買う
    int n = min(X, Y);
    a += n;
    b += n;

    int x_rest = X - n;
    int y_rest = Y - n;

    // Aピザ1枚 or ABピザ2枚の安い方で購入する
    if ((C * 2) < A) {
      ab += x_rest * 2;
    } else {
      a += x_rest;
    }

    // Bピザ1枚 or ABピザ2枚の安い方で購入する
    if ((C * 2) < B) {
      ab += y_rest * 2;
    } else {
      b += y_rest;
    }
  }

  cout << (A * a + B * b + C * ab) << endl;
  return 0;
}
