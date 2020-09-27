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

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  // 全探索
  for (int i = 0; i < 10; i++) {
    if (i > 0) { cout << ", "; }
    cout << fibonacci(i);
  }
  cout << "\n";
  cout << "counter: " << counter << "\n";

  return 0;
}
