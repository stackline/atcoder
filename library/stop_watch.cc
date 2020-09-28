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
  // gcc 9.3.0 の cout.precision() は 6 を返す。これは整数部を含めた桁数指定。
  // sw.elapsed_ms() = 1234567 マイクロ秒を計測した場合、ミリ秒は 1234.567 ミリ秒となる。
  // デフォルト設定のまま cout で出力すると、precision の設定に従い 1234.56 と出力する。
  // 0.001 まで表示する場合、cout << fixed << setprecision(3) や、以下の printf のように、小数点以下の出力桁数を指定する。
  printf("elapsed: %.3f millisec\n", sw.elapsed_high_precision_ms()); // マイクロ秒から算出したミリ秒
  cout << "elapsed: " << sw.elapsed_sec() << " sec" << "\n"; // 秒

  return 0;
}
