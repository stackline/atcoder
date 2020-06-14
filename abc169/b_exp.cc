#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int zero = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == 0) {
      zero++;
    }
  }
  // N個の正数の中に 0 が含まれる
  if (zero > 0) {
    cout << 0 << endl;
    return 0;
  }

  // 64bit
  // 10**19 < 2**64 < 10**20
  ll prod = 1;
  for (int i = 0; i < N; i++) {
    // prod * A.at(i) <= 10**18 で比較を行う場合、
    // 左辺の prod * A.at(i) の計算結果が long long 型の扱える範囲を
    // 超える可能性がある。
    //
    // A.at(i) <= 10**18 / prod の除算で比較を行うことにより、
    // オーバーフローを回避する。
    //
    // prod * A.at(i) の計算結果がオーバフローするような入力例の場合、
    // 事前に if 文の A.at(i) <= 10**18 / prod の判定が false となり、
    // -1 が出力される
    if (A.at(i) <= 1000000000000000000 / prod) {
      prod = prod * A.at(i);
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << prod << endl;
  return 0;
}
