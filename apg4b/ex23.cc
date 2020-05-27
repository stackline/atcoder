#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; // <= 10^5 = 100_000
  cin >> N;

  // 文字列をキーとする連想配列を作成する
  map<string, int> m;
  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;
    if (m.count(a)) {
      m[a]++;
    } else {
      m[a] = 1;
    }
  }

  int max_times = 0;
  for (auto x : m) {
    max_times = max(max_times, x.second);
  }

  string max_times_num;
  for (auto x : m) {
    if (x.second == max_times) {
      max_times_num = x.first;
    }
  }

  cout << max_times_num << " " << max_times << endl;
  return 0;
}
