#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// フィボナッチ数列
//
// f(0) = 0
// f(1) = 1
// f(n+2) = f(n+1) + f(n) (n >= 0)
// f(n) = f(n-1) + f(n-2) (n >= 2)

// 全探索
int counter = 0;
int fibonacci(int n) {
  counter++;
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  return fibonacci(n-1) + fibonacci(n-2);
}

// メモ探索
int memoized_counter = 0;
int memoized_fibonacci(vector<bool> &done, vector<int> &memo, int n) {
  memoized_counter++;

  if (done.at(n)) {
    return memo.at(n);
  }

  int num;
  if (n == 0) {
    num = 0;
  } else if (n == 1) {
    num = 1;
  } else {
    num = memoized_fibonacci(done, memo, n-1) + memoized_fibonacci(done, memo, n-2);
  }

  done.at(n) = true;
  memo.at(n) = num;

  return num;
}

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n = 10;

  // 全探索
  for (int i = 0; i < n; i++) {
    if (i > 0) { cout << ", "; }
    cout << fibonacci(i);
  }
  cout << endl;
  cout << "counter: " << counter << endl;

  // メモ探索
  vector<bool> done(n, false);
  vector<int> memo(n);
  for (int i = 0; i < n; i++) {
    if (i > 0) { cout << ", "; }
    cout << memoized_fibonacci(done, memo, i);
  }
  cout << endl;
  cout << "memoized_counter: " << memoized_counter << endl;

  return 0;
}
