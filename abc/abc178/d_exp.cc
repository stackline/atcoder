#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll modinv(ll a, ll m) {
  ll b = m;
  ll u = 1;
  ll v = 0;

  while (b) {
    ll t = a / b;
    a = a - (t * b);
    swap(a, b);
    u = u - (t * v);
    swap(u, v);
  }
  u = u % m;
  if (u < 0) u += m;
  return u;
}

ll combination(ll n, ll k) {
  ll num = 1;
  for (int i = 1; i <= k; i++) {
    // num = num * (n - i + 1) / i;
    ll a = num * (n - i + 1) % mod;
    ll b = modinv(i, mod) % mod;
    ll c = (a * b) % mod;
    num = c;
  }
  return num;
}

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int s;
  cin >> s;

  int max_divisions = s / 3;

  ll ans = 0;
  for (int i = 1; i <= max_divisions; i++) {
    // 分割数が 1 の場合
    if (i == 1) {
      // A = [S] の1通り
      ans += 1;
    // 分割数が 2 以上の場合
    } else {
      // 分配するべき残りのボールの数
      //
      // ### 例
      // s=7 とする。
      //   o o o o o o o
      // i=2 のため、これを2分割する。
      // 分割された各グループは、最低3つのボールを持つ。
      //   o o o | o o o
      // これより、分配するべき残りのボールの個数は以下となる。
      //   s - (i * 3) = 7 - (2 * 3) = 1
      //
      int remaining = s - (i * 3);
      // 区切りの数
      int separation = i - 1;
      // 組み合わせの数を求める
      ans = (ans + combination(remaining + separation, separation)) % mod;
    }
  }

  cout << ans << endl;
  return 0;
}
