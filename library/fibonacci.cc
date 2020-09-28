#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct StopWatch {
  chrono::system_clock::time_point start_pt;
  chrono::system_clock::time_point end_pt;

  void start() {
    start_pt = chrono::system_clock::now();
  }

  void stop() {
    end_pt = chrono::system_clock::now();
  }

  // ナノ秒
  long long elapsed_ns() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::nanoseconds sec = chrono::duration_cast<chrono::nanoseconds>(elapsed);
    return static_cast<long long>(sec.count());
  }
  // マイクロ秒
  long long elapsed_us() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::microseconds sec = chrono::duration_cast<chrono::microseconds>(elapsed);
    return static_cast<long long>(sec.count());
  }
  // ミリ秒
  long long elapsed_ms() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::milliseconds sec = chrono::duration_cast<chrono::milliseconds>(elapsed);
    return static_cast<long long>(sec.count());
  }
  // マイクロ秒から算出したミリ秒
  double elapsed_high_precision_ms() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::microseconds sec = chrono::duration_cast<chrono::microseconds>(elapsed);
    return static_cast<double>(sec.count()) / 1000.0;
  }
  // 秒
  long long elapsed_sec() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(elapsed);
    return static_cast<long long>(sec.count());
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

// 動的計画法
void dp_fibonacci(vector<int> &dp, int n) {
  dp.at(0) = 0;
  dp.at(1) = 1;
  for (int i = 2; i <= n; i++) {
    dp.at(i) = dp.at(i-1) + dp.at(i-2);
  }
}

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n = 42;
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
  printf("elapsed: %.3f ミリ秒\n", sw.elapsed_high_precision_ms());

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
  printf("elapsed: %.3f ミリ秒\n", sw.elapsed_high_precision_ms());

  // 動的計画法
  cout << "# dp" << endl;
  vector<int> dp(n+1);
  sw.start();
  dp_fibonacci(dp, n);
  for (int i = 0; i < n; i++) {
    if (i > 0) { cout << ", "; }
    cout << dp.at(i);
  }
  sw.stop();
  cout << endl;
  printf("elapsed: %.3f ミリ秒\n", sw.elapsed_high_precision_ms());

  return 0;
}
