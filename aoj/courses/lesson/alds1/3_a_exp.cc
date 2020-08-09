#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TinyStack {
  int S[101]; // データを格納するための整数型1次元配列
  int top;    // スタックポインタを表す整数型変数

  // コンストラクタ
  TinyStack() {
    top = 0;
  }
  // スタックに要素 x を追加する関数
  void push(int x) {
    top++;
    S[top] = x;
  }
  // スタックのトップから要素を取り出す関数
  int pop() {
    int val = S[top];
    top--;
    return val;
  }
};

bool is_number(string s) {
  auto condition = [](char c) {
    return isdigit(c);
  };
  return all_of(s.begin(), s.end(), condition);
}

void calc(TinyStack &sk, string op) {
  int right = sk.pop();
  int left = sk.pop();

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
  TinyStack sk;
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

  cout << sk.pop() << endl;
  return 0;
}
