#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int popcount(int x) {
  return __builtin_popcount(x);
}

int f(int x) {
  // ベースケース
  if (x == 0) {
    return 0;
  }
  // 再起ステップ
  return f(x % popcount(x)) + 1;
}


int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    x.at(i) = s.at(i) - '0';
  }

  // X0 の popcount
  int pc = 0;
  for (int i = 0; i < n; i++) {
    pc += x.at(i);
  }

  vector<int> ans(n, 0);
  for (int bit = 0; bit < 2; bit++) {
    int npc = pc;
    // bit = 0 の場合、0 から 1 に flip する
    // bit = 1 の場合、1 から 0 に flip する
    if (bit == 0) { npc++; } else { npc--; }

    // 例えば X0 が2進数で 10000 の場合 (10進数で16の場合)
    // pc = 1 となる。
    // 5桁目の 1 を 0 に flip すると npc = 0 となる。
    // 後続の処理で、ゼロ除算による Runtime Error が発生するケースがある。
    // そのため、ここで例外処理を行う。
    //
    // 2進数の 00000 は10進数の 0 である。
    // X0 = 10000 と仮定した場合、X1 = 00000 となる。
    // f(00000) について、0 の場合の操作回数は 0 である。
    //
    // vector を宣言した際に、各要素は 0 で初期化されているため、
    // 後続処理は行わなくてよく、ここで処理をスキップする。
    if (npc == 0) { continue; }

    // flip 後の popcount で x0 を割った余りを求める
    int r0 = 0;
    for (int i = 0; i < n; i++) {
      int sum = r0 * 2 + x.at(i);
      // 2進数を10進数に変換した後、余りを求めると、
      // int や long long 型の範囲を超えるため、都度、余りを求める
      r0 = sum % npc;
    }

    int k = 1;
    for (int i = n - 1; i >= 0; i--) {
      // bit = 0 の場合、0 から 1 に flip する
      // bit = 1 の場合、1 から 0 に flip する
      if (x.at(i) == bit) {
        int remainder = r0;
        // 0 から 1 に flip するので、余りを加算する
        // * 2進数 11011 の余りは 27 % 5 = 2
        // * 3ビット目の 0 を 1 に flip した場合、2**2 % 5 = 4 余りが増える
        // * X0 の余り (2) と flip して増加した X3 の余り (4) を合計すると 6 になる
        // * 6 は npc = 5 より大きいため、余りは 1 となる
        if (bit == 0) {
          remainder = (remainder + k) % npc;
        // 1 から 0 に flip するので、余りを減算する
        } else {
          remainder = (remainder - k + npc) % npc;
        }

        // remainder は「Xi を popcount(Xi) で割った余りに置き換える」
        // という操作を1回した結果である
        ans.at(i) = f(remainder) + 1;
      }

      // n 桁目のビットを反転させた際に、増減する余りの数
      // * 次のループで利用される
      k = (k * 2) % npc;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans.at(i) << endl;
  }
  return 0;
}
