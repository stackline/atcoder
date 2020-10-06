#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 O(N)
// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;

  int ans = 0;

  // a * b + c = n という式を満たす。
  // (a, b) の組が定まると、c は1つに定まる。なぜなら c = n-(a*b) であるため。
  // そのため、(a, b) の組の数を数えれば、それが問題の回答となる。
  //
  // a,b,c はいずれも正の整数であるため、b, c が取りうる最小の値である 1 の場合、
  // a * 1 + 1 = n より a = n-1 となり、これが a の数の取りうる最大の値である。
  //
  // a の値を 1 〜 n-1 に固定して、その際に b が取りうる値の数を算出する。
  //
  //   c=1 の時、a * b は最大の値を取る。
  //   a の値が 1 〜 n-1 に変化する場合、b が取りうる最大の値は以下である。
  //
  //     a * b + c = n
  //     b = (n-c) / a
  //     b = (n-1) / a
  //
  //   例えば n = 5、a = 2 の場合、b = (5-1) / 2 = 2 である。(floor で小数を切り捨てる)
  //   これより b の取りうる値は 1 〜 2 である。
  //   (a, b) の組で言うと、以下の2組が取りうる組である。
  //
  //     (a, b) = (2, 1), (2, 2)
  //
  //   b が (n-1) / a より大きい値を取る場合、(a, b) = (2, 3) より a * b = 6 で n = 5 を超えてしまう。
  //
  // a = 1 〜 n-1 について、b の取りうる値の数を全探索し、それらの数を足し合わせると、回答となる。
  //
  for (int a = 1; a < n; a++) {
    int cnt = (n-1) / a;
    ans += cnt;
  }

  cout << ans << endl;
  return 0;
}
