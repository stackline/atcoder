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
    // ### 剰余の値が計算の順序で変わらないように、i の逆元を求めて掛け算にする
    //
    // 組み合わせを計算する際のベースの計算式は以下。
    // i の割り算が存在すると、計算の順序で mod の値が異なるため、割り算を使わない形にする。
    //
    //   num = num * (n - i + 1) / i;
    //
    // ### 変数 a と変数 b でそれぞれ mod を取り、オーバーフローを避ける
    //
    // long long = signed long long である。
    // signed のため、2**64 / 2 = 9223372036854775807 がデータ型の上限である。
    // 変数 a と変数 b を mod を取らずに掛け合わせると、オーバーフローするケースがあるため、細かく mod を取る。
    //
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

  // ### 方針
  //
  // * 分割数を 1 〜 floor(s/3) でパターン分けする。
  // * それぞれのパターンについて、「同質のボール」の残りを各グループに分配する。
  // * 分配する際は、全く分配されないグループがあってもよい。
  // * 重複組み合わせの問題を「仕切り」の問題と捉えて、組み合わせの数を数える。
  //   * 「分配するもの」と「仕切り（分割数 - 1）」を一列に並べる組み合わせの数
  // * ref. https://mathtrain.jp/tyohukuc
  //
  // ### 例 (S=10 の場合)
  //
  // 10個のボールがあると考える。
  //
  //   o o o o o o o o o o
  //
  // 取りうる分割数のパターンを考える。
  //
  //   最小分割数は 1 である。つまり分割しないパターン。
  //   最大分割数は floor(s/3) である。つまり floor(10/3)=3 である。
  //
  // 分割数=1 の場合
  //
  //   o o o o o o o o o o --> {10} の1通り
  //
  // 分割数=2 の場合
  //
  //   分割した2つのグループは、それぞれ最低3つのボールを持つ。
  //
  //     o o o | o o o
  //
  //   残りのボールの数は s - (分割数 * 3) = 4 である。
  //
  //     s - (分割数 * 3) = 10 - (2 * 3) = 4
  //
  //   この4つのボールを2つのグループに分配する。
  //   4つのボールの間に1つの仕切りを入れる。
  //
  //     | o o o o --> {3, 7}
  //     o | o o o --> {4, 6}
  //     o o | o o --> {5, 5}
  //     o o o | o --> {6, 4}
  //     o o o o | --> {7, 3}
  //
  //   これは4つのボールと1つの区切りを一列に並べる時の、場合の数である。
  //   区切りの位置を5箇所から1箇所選択する組み合わせの数と考えると、以下となる。
  //
  //     5C1 = (5 / 1) = 5通り
  //
  // 分割数=3 の場合
  //
  //   分割した3つのグループは、それぞれ最低3つのボールを持つ。
  //
  //     o o o | o o o | o o o
  //
  //   残りのボールの数は s - (分割数 * 3) = 1 である。
  //
  //     s - (分割数 * 3) = 10 - (3 * 3) = 1
  //
  //   この1つのボールを3つのグループに分配する。
  //   1つのボールの間に2つの仕切りを入れる。
  //
  //     | | o --> {3, 3, 4}
  //     | o | --> {3, 4, 3}
  //     o | | --> {4, 3, 3}
  //
  //   これは1つのボールと2つの区切りを一列に並べるための、場合の数である。
  //   区切りの位置を3箇所から2箇所選択する組み合わせの数と考えると、以下となる。
  //
  //     3C2 = (3*2 / 2*1) = 3通り
  //
  // 数列の数
  //
  //   分割数=1 の場合 1通り {10}
  //   分割数=2 の場合 5通り {3, 7} {4, 6} {5, 5} {6, 4} {7, 3}
  //   分割数=3 の場合 3通り {3, 3, 4} {3, 4, 3} {4, 3, 3}
  //   合計 9 通り
  //
  int max_divisions = s / 3;

  ll ans = 0;
  for (int i = 1; i <= max_divisions; i++) {
    // 分割数が 1 の場合
    if (i == 1) {
      // A = [S] の1通り
      ans += 1;
    // 分割数が 2 以上の場合
    } else {
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