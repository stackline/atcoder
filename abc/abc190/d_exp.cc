#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  // 初項: S (整数)
  // 長さ: L (> 0)
  // 総和: N = 平均 * 長さ
  //         = (初項 + 末項) / 2 * 長さ
  //         = (S + (S + L - 1)) / 2 * L ... (a)
  //
  // (a) の式を変形する。
  //
  //   (2S + L - 1) / L = 2N
  //   2S + L - 1 = 2N / L
  //   2S = (2N / L) - L + 1
  //   S = ((2N / L) - L + 1) / 2
  //
  // S が整数である条件
  //
  //   * ((2N / L) - L + 1) が偶数であること
  //   * (2N / L) が整数であること
  //   * L が 2N の約数であること
  //

  // L が 2N の約数である場合、対となる数が存在する。
  //
  //   例: N = 12 の場合
  //   (1, 12) (2, 6) (3, 4)
  //
  // x,y を 2N の約数とする。
  //
  //   2N = x * y
  //
  // x を決めると、y が決まる。
  // x の探索範囲は sqrt(2N) まででよい。
  //   x = sqrt(2N) の場合、x * x = 2N となる。
  //
  //   x > sqrt(2N) の範囲での (x,y) の組み合わせは、
  //   x <= sqrt(2N) の範囲での (x,y) の組み合わせについて、
  //   x,y を逆にしたものである。
  //
  ll n;
  cin >> n;

  ll n2 = n * 2;
  int ans = 0;
  auto check = [&](ll l) {
    ll tmp = n2 / l - l + 1;
    // NOTE: abs で絶対値とらなくてもよい
    // tmp がプラスの値、マイナスの値に関わらず、割り切れる場合、
    // 剰余は 0 となる。
    if (tmp % 2 == 0) {
      ans++;
    }
  };

  // x = 項数 L とする
  for (ll x = 1; x * x <= n2; x++) {
    // x が約数でなければスキップ
    if (n2 % x != 0) {
      continue;
    }
    // x の対となる約数 y を求める
    ll y = n2 / x;

    // 条件を満たすかどうかチェックする
    check(x);
    // 16 = 4 x 4 のように、x と y が同じ値の場合は、
    // 二重カウントしないように x のみ check する。
    //
    // ただし、2N = x * y について、x と y の偶奇は異なるため、
    // x と y が同じ値のとき、check は true とならない。
    if (x != y) {
      check(y);
    }
  }

  cout << ans << endl;
  return 0;
}
