#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".
}

int main() {
  init();
  int n;
  cin >> n;

  const int mod = 1e9+7;

  // 全パターン
  // = 数列のどの項も、0-9 の数字である数列
  // パターン数 : 10**n
  ll a = 1;
  // Ai=0 なる i が存在しないような数列
  // = 数列のどの項も 1-9 の数字である数列
  // パターン数 : 9**n
  ll b = 1;
  // Ai=9 なる i が存在しないような数列
  // = 数列のどの項も 0-8 の数字である数列
  // パターン数 : 9**n
  ll c = 1;
  // Ai=0 なる i も Ai=9 なる i も存在しないような数列
  // = 数列のどの項も 1-8 の数字である数列
  // パターン数 : 8**n
  ll d = 1;
  for (int i = 0; i < n; i++) {
    a = a * 10 % mod;
    b = b * 9 % mod;
    c = c * 9 % mod;
    d = d * 8 % mod;
  }

  ll ans = (a - b - c + d) % mod;
  // 例えば n=20 の場合 (a-b-c+d) % mod < 0 となる (ans = -370140969)
  // そのため、mod を必要な回数だけ加算して正の数にする
  //
  // cout << "a: " << a << "\n";
  // cout << "b: " << b << "\n";
  // cout << "c: " << c << "\n";
  // cout << "d: " << d << "\n";
  // cout << "ans: " << ans << "\n";
  while (ans < 0) {
    ans = ans + mod;
  }
  cout << ans << "\n";
  return 0;
}
