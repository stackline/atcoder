#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int l;
  cin >> l;

  // ### L=20の場合
  //
  // 20個の o がある。
  // 20個の o と o の間には19箇所の隙間がある。
  // 19箇所の隙間の内、11箇所を選ぶ組み合わせの数 19C11 を求める。
  //
  // この時、分母のみ・分子のみを計算したのち、分母を分子で割ると、
  // L の値が大きい時に、計算途中の値が大きくなり、オーバーフローする。
  //
  //   (19!) / (11! * (19-11)!)
  //
  // そのため、計算途中の値ができるだけ大きくならないように
  // 都度割りながら、計算する。
  //
  //  19/1 * 18/2 * 17/3 * ... * 10/10 * 9/11
  //
  // なお、計算の途中の式は割り切れる数となる。
  //
  //  19C1 = 19/1
  //  19C2 = 19/1 * 18/2
  //  19C3 = 19/1 * 18/2 * 17/3
  //
  ll k = 11;
  ll ans = 1;
  for (int i = 1; i <= k; i++) {
    ans = ans * (l - i);
    ans = ans / i;
  }
  cout << ans << endl;
  return 0;
}
