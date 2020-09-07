#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  const int A = 1e6+1;

  vector<int> a(n);
  vector<int> c(A);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    c.at(a.at(i))++;
  }

  bool pairwise = true;
  // ### 計算量
  //
  //     A
  // O(sigma(A/i))
  //    i=1
  //
  //         A
  // O(A * sigma(1/i))
  //        i=1
  //
  //         A
  // O(A * sigma(1/i))
  //        i=1
  //
  // 右辺が調和級数である
  // 右辺の数列を展開すると以下になる。
  //
  //   a = 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + ...
  //
  // これを上から押さえると a < b となる。
  //
  //   b = 1 + (1/2 + 1/2) + (1/4 + 1/4 + 1/4 + 1/4) + (1/8 + ...) + ...
  //
  // A = 16 と仮定すると a, b は以下となる
  //
  //   a = 1 + 1/2 + 1/3 + ... + 1/15 + 1/16
  //   b = 1 + (1/2 + 1/2) + ... (1/8 + ... + 1/8) + 1/16
  //     = 1 + 1 + 1 + 1 + 1/16
  //
  // これらより、a の計算量の最大値は log2(A) + 1/A より小さい
  //
  //   b = log2(A) + 1/A
  //   a < log2(A) + 1/A
  //
  // 最初の数列より
  //
  //         A
  // O(A * sigma(1/i))
  //        i=1
  //
  // = O(A * (log2(A) + 1/A))
  // = O(A log2(A) + 1)
  // = O(A log2(A))
  //
  for (int i = 2; i < A; i++) {
    int cnt = 0;
    // ### 例: A = { 6, 10, 15 } の場合
    //
    // * c[6] = 1
    // * c[10] = 1
    // * c[15] = 1
    //
    // 2〜A までの数について、倍数の登場回数をカウントする
    //
    // * i=2 の場合
    //   * cnt = 2 (6, 10)
    //   * つまり素因数として 2 を持つ数が、集合の中に2件以上存在する
    // * i=3 の場合
    //   * cnt = 2 (6, 15)
    // * i=5 の場合
    //   * cnt = 2 (10, 15)
    //
    for (int j = i; j < A; j=j+i) {
      cnt = cnt + c.at(j);
    }
    // ### cnt > 1 を満たすケース
    // i = 2 を例とすると gcd(6, 10) = 2 となる。
    //
    // 集合の中の 2 つ以上の数が、共通の素因数 p で構成されていると、
    // gcd(Ai, Aj) = p となり、gcd(Ai, Aj) = 1 が成立しない。
    //
    // そのため pairwise coprime ではない。
    if (cnt > 1) {
      pairwise = false;
    }
  }

  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  // ### 例: A = { 6, 24, 15 } の場合
  //
  // g = 0
  //   g = gcd(0, 6) = 6
  // g = 6
  //   g = gcd(6, 24) = 6
  // g = 15
  //   g = gcd(6, 15) = 3
  //
  // 最終的に g = 3 となる
  //
  int g = 0;
  for (int i = 0; i < n; i++) {
    g = gcd(g, a.at(i));
  }
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;
  return 0;
}
