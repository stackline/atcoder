#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int a = 0; // R->W に変更する回数
  int b = 0; // W->R に変更する回数

  // ### 0回目
  // 全て白にするケースについて、回数を数える。
  // 以下の場合だと、Rが4つあるので a=4 となる。
  //
  // * before: WRWWRWRR
  // * after:  WWWWWWWW
  //
  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'R') {
      a++;
    }
  }

  int ans = max(a, b);
  for (int i = 0; i < n; i++) {
    // i番目の要素がRの場合、R->W が R->R に変わったため、a の実行回数が減る
    if (s.at(i) == 'R') {
      a--;
    // i番目の要素がWの場合、W->W が W->R に変わったため、b の実行回数が増える
    } else {
      b++;
    }
    // 実行回数は「a, b の最大の方」が、操作の最小回数となる。
    // 逆に言うと a, b の最小の方の回数だけ swap を行い、残りの回数だけ R と W の色を入れ替える。
    //
    // 例えば a = 3, b = 2 の場合、
    // * swap を2回行う
    //   * a (R->W) が -2 となる
    //   * b (W->R) が -2 となる
    // * a について、R->W を1回行う
    //   * a (R->W) が -1 となる
    int now = max(a, b);
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}
