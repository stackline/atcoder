#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  // (1) カコモンジム --> AtCoderジムの順番で1回ずつジムに通った場合
  //
  //   強さ: X * A + B = AX + B
  //   経験値: 2
  //
  // (2) AtCoderジム --> カコモンジムの順番で1回ずつジムに通った場合
  //
  //   強さ: (X + B) * A = AX + AB
  //   経験値: 2
  //
  // (3) 同じ経験地に到達するために、(1) の方がより強さの増加量が少なくて済む。

  // カコモンジムに通える最大回数を求める
  ll x1 = x;
  ll kakomon_max = 0;

  while (1) {
    // x * a >= y で超過判定すると、左辺がオーバーフローする可能性があるため、
    // 右辺に移行し、x >= y / a とする。
    //
    //   x=3, y=8, a=3 とする。
    //
    //   ### x * a >= y の場合
    //   3 * 3 >= 8
    //   9 >= 8 より true となる。
    //
    //   ### x >= y / a の場合
    //   3 >= 8 / 3
    //   3 >= 2 より true となる。
    //
    //   右辺が double 型の場合は 2.666... となる。
    //   今回は右辺が long long 型のため、小数以下を切り捨て 2 と計算する。
    //   2 も 2.666... もいずれも 3 >= (y / a) を満たすため、
    //   小数点以下の切り捨ての有無に関わらず、判定内容は変わらない。
    //
    // 参考: 以下の入力例の場合、x * a >= y で計算するとオーバーフローする
    //
    //   x: 1000000000000000000
    //   y: 1000000000000000000
    //   a: 1000000000
    //   b: 1000000000
    //
    if (x1 >= y / a) {
      break;
    }
    x1 = x1 * a;
    kakomon_max++;
  }

  ll ans = 0;
  ll x2 = x;
  // i はカコモンジムに通う回数である。
  // 0 〜 kakomon_max 回通うそれぞれのケースについて、
  //
  // 強さが Y 未満という条件を満たした上で、AtCoderジムに最大何回通えるかを計算する。
  for (int i = 0; i <= kakomon_max; i++) {
    // 0回目は強さを増やさない
    if (i >= 1) {
      x2 = x2 * a;
    }
    ll rest = y - x2 - 1;
    ll exp = i + (rest / b);
    ans = max(ans, exp);
  }

  cout << ans << endl;
  return 0;
}
