#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_number(string s) {
  auto condition = [](char c) {
    return isdigit(c);
  };
  return all_of(s.begin(), s.end(), condition);
}

void calc(stack<int> &sk, string op) {
  // 1 2 + という標準入力の場合、引数は以下となる。
  //
  // * stack: |2|1|
  // * operator: +
  //
  // この引数から 1 + 2 = 3 という計算を行い、計算結果の |3| を stack に push する。
  // これより、最初に取り出すオペランドが右辺、2番目に取り出すオペランドが左辺となる。
  int right = sk.top();
  sk.pop();
  int left = sk.top();
  sk.pop();

  int result = 0;
  if (op == "+") {
    result = left + right;
  } else if (op == "-") {
    result = left - right;
  } else if (op == "*") {
    result = left * right;
  }

  // cout << left << " " << op << " " << right << " = " << result << endl;
  sk.push(result);
}

int main() {
  stack<int> sk;
  string symbol;

  while (cin >> symbol) {
    // オペランドの場合
    if (is_number(symbol)) {
      sk.push(stoi(symbol));
    // 演算子の場合
    } else {
      calc(sk, symbol);
    }
  }

  cout << sk.top() << endl;
  return 0;
}
