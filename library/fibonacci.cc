#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct StopWatch {
  clock_t start_ct;
  clock_t stop_ct;

  void start() {
    start_ct = clock();
  }
  void stop() {
    stop_ct = clock();
  }
  double elapsed() {
    double in_seconds = (double) (stop_ct - start_ct) / CLOCKS_PER_SEC;
    double in_milliseocnds = in_seconds * 1000.0;
    return in_milliseocnds;
  }
};

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

  int n = 16;
  StopWatch sw;

  // 全探索
  cout << "# Full search" << endl;
  sw.start();
  for (int i = 0; i < n; i++) {
    if (i > 0) { cout << ", "; }
    cout << fibonacci(i);
  }
  sw.stop();
  cout << endl;
  cout << "counter: " << counter << endl;
  printf("elapsed: %lf[ms]\n", sw.elapsed());

  // メモ探索
  cout << "# memoized search" << endl;
  vector<bool> done(n, false);
  vector<int> memo(n);
  sw.start();
  for (int i = 0; i < n; i++) {
    if (i > 0) { cout << ", "; }
    cout << memoized_fibonacci(done, memo, i);
  }
  sw.stop();
  cout << endl;
  cout << "counter: " << memoized_counter << endl;
  printf("elapsed: %lf[ms]\n", sw.elapsed());

  return 0;
}
