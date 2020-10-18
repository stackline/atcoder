#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (N / i != i)
        res.push_back(N / i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and
  // "scanf/printf".

  ll n;
  cin >> n;

  const auto &res = enum_divisors(n);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res.at(i) << endl;
  }

  return 0;
}
