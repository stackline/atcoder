// #include <bits/stdc++.h>
#include <iostream>
#include <thread> // this_thread::
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
  // 秒
  long long elapsed_sec() {
    chrono::system_clock::duration elapsed = end_pt - start_pt;
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(elapsed);
    return static_cast<long long>(sec.count());
  }
};

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  StopWatch sw;
  sw.start();
  this_thread::sleep_for(chrono::seconds(3));
  sw.stop();
  cout << "elapsed: " << sw.elapsed_ns() << " nanosec" << "\n"; // ナノ秒
  cout << "elapsed: " << sw.elapsed_us() << " microsec" << "\n"; // マイクロ秒
  cout << "elapsed: " << sw.elapsed_ms() << " millisec" << "\n"; // ミリ秒
  cout << "elapsed: " << sw.elapsed_sec() << " sec" << "\n"; // 秒

  return 0;
}
