#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;
  vector<ll> x(n);

  // X = 高橋氏の得る票数 - 青木氏の得る票数
  // とする。
  //
  // 高橋氏が演説を行わなかった場合、高橋派の人は投票を行わない。
  // X はマイナスとなる。
  //
  //   X = 0 - 青木氏の得る票数
  //
  // 高橋氏が1回演説を行うと、青木氏の票数が a 票減る。
  // 高橋氏が1回演説を行うと、高橋氏の票数が a + b 票増える。
  // 高橋氏が1回演説を行うと、合計で X の値は 2a + b 票増える。
  //
  // X > 0 の場合、高橋氏の得る票数は、青木氏の得る票数を超える。
  //
  //   X > 0
  //   --> 高橋氏の得る票数 - 青木氏の得る票数 > 0
  //   --> 高橋氏の得る票数 > 青木氏の得る票数
  //
  // X > 0 を満たすまで、演説を繰り返せばよい。
  //
  ll X = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    X -= a;
    x.at(i) = a + a + b;
  }

  sort(x.rbegin(), x.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    X += x.at(i);
    ans++;
    if (X > 0) {
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}
