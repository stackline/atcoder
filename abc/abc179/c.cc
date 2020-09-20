#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}


// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;

  const int max = 1e6;

  vector<int> v(max+1);
  for (int i = 1; i <= max; i++) {
    // i=12 の場合
    //   { {2, 2}, {3, 1} }
    // i=1000 の場合
    //   { {2, 3}, {5, 3} }
    const auto &res = prime_factorize(i);
    int x = 1;
    for (auto p : res) {
      x = x * (p.second+1);
    }
    v.at(i) = x;
  }

  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = ans + v.at(i);
  }
  cout << ans << endl;
  return 0;
}
