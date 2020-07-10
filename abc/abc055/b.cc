#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  ll divisor = 1000000007;
  ll power = 1;
  for (int i = 1; i <= n; i++) {
    // cout << power << " * " << i << " = ";
    power = power * i;
    //
    // power が 10^9 + 7 を超えた場合、
    // power を 10^9 + 7 で割った際の剰余と同じ値の剰余を算出する、
    // 10^9 + 7 以下の最大の商を算出することで、桁あふれを防ぐ。
    //
    // 例: 商を 99099、除数を 100 とする。
    // 99099 % 100 = 99 で、剰余は 99 となる。
    //
    // 除数 100 以下の値の中で、剰余が 99 となる最大の数は 99 である。
    // 99 % 100 = 99
    //
    // 99099 を 2 倍した場合、除数 100 で割った際の剰余は
    // 198198 % 100 = 98 となる。
    // 99 を 2 倍した場合、除数 100 で割った際の剰余は
    // 198 % 100 = 98 となる。
    //
    // 定期的に商を桁あふれしないようにしている。
    //
    if (power >= divisor) {
      power = power % divisor;
    }
    // cout << power << endl;
  }

  cout << power << endl;
  return 0;
}
