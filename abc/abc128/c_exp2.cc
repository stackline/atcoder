#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--;
      //
      // ビット和代入 "|=" で、スイッチがどの電球につながっているかを
      // 2進数で管理する
      //
      // ### データ例
      // k s1 s2
      // 2  1  2
      // 1  1
      // 1  2
      //
      // ### スイッチの番号を 0-indexed に変換
      // k s1 s2
      // 2  0  1
      // 1  0
      // 1  1
      //
      // i=0
      //   a[0] |= 1 << 0;
      //     000 | 001 = 001
      //     a[0] = 001
      //   a[1] |= 1 << 0;
      //     000 | 001 = 001
      //     a[1] = 001
      // i=1
      //   a[0] |= 1 << 1;
      //     001 | 010 = 011
      //     a[0] = 011
      // i=2
      //   a[1] |= 1 << 2;
      //     001 | 100 = 101
      //     a[1] = 101
      //
      // ### 出来上がるデータ
      // a[0] = 011 // 0個目のスイッチは電球 0,1 につながっている
      // a[1] = 101 // 1個目のスイッチは電球 0,2 につながっている
      //
      a.at(s) |= 1 << i;
    }
  }

  int p = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    // ### 処理の流れ
    //
    // p1 p2 p3
    // 0  0  1
    //
    // p = 000 | 0<<0 = 000
    // p = 000 | 0<<1 = 000
    // p = 000 | 1<<2 = 000 | 100 = 100
    //
    // 各電球につながっているスイッチについて、点灯条件が管理される。
    // 点灯条件は「スイッチが on になっている数の偶奇」である。
    //
    // 例えば2個目の電球の場合は on になっているスイッチの数が偶数であること。
    // つまり、onのスイッチの数が0個 or 2個の場合に点灯する。
    // しかし、2個目の電球は1つのスイッチと紐づいている。
    // そのため、onのスイッチが0個の場合に点灯する。
    //
    p |= x<<i;
  }

  int ans = 0;
  for (int s = 0; s < (1 << n); s++) {
    int t = 0; // どの電球がついているか

    // スイッチのon,offパターンのbit全探索
    //
    // * スイッチ0のみが on の場合
    //   * s = 1 = 2進数で表すと 01 となる
    // * a[0] との XOR で、0個目のスイッチにつながっている電球について、
    //   bitを立てることで、電球ごとに on になっているスイッチの数の偶奇がわかる
    //
    // * スイッチ0 と 1 が両方 on の場合
    // * a[0] a[1] との XOR で、電球ごとに on になっているスイッチの数の偶奇がわかる
    //
    // ### 処理の流れ
    //
    // s=0 (00)
    //   i=0 のスイッチ 00 >> 0 & 1 = 0
    //   i=1 のスイッチ 00 >> 1 & 1 = 0
    //   --> t=000
    //
    // s=1 (01)
    //   i=0 のスイッチ 01 >> 0 & 1 = 1
    //     t = 000 ^ a.at(0) = 000 ^ 011 = 011
    //   i=1 のスイッチ 01 >> 1 & 1 = 0
    //   --> t=011
    //
    // s=2 (10)
    //   i=0 のスイッチ 10 >> 0 & 1 = 0
    //   i=1 のスイッチ 10 >> 1 & 1 = 1
    //     t = 000 ^ a.at(1) = 000 ^ 101 = 101
    //   --> t=101
    //
    // s=3 (11)
    //   i=0 のスイッチ 11 >> 0 & 1 = 1
    //     t = 000 ^ a.at(0) = 000 ^ 011 = 011
    //   i=1 のスイッチ 11 >> 1 & 1 = 1
    //     t = 011 ^ a.at(1) = 011 ^ 101 = 110
    //   --> t=110
    //
    for (int i = 0; i < n; i++) {
      if (s >> i & 1) {
        // XOR演算子
        t ^= a.at(i);
      }
    }

    // p = 100 の場合、全ての電球が点灯する
    // 一方で t は bit 全探索した全てのパターンで 100 になることはない
    // そのため、ans がインクリメントされることはない
    if (t == p) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
