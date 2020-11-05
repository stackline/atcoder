#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ナイーブな解法
// 計算量: O(CT + T) = O(CT)
//
// お客さんごとに S[i] から E[i]-1 の間の値についてカウントを 1 増やす
//
// E[i] を -1 するのは、常に、出店が入店より先に行われるため。
// これを -1 しない場合、出店と入店が共に発生する時刻について、
// 出店者と入店者を合わせてカウントすることになる。
//
// ### データ例
//
// 1人目: 1時〜4時
// 2人目: 3時〜5時
//
//  1   2   3   4   5
//  in  --- --- out
//          in  --- out
//
// ### -1 しない場合
//
// 3時: 2名
// 4時: 2名 (出店する人と入店する人をカウント)
//
// ### -1 する場合
//
// 3時: 2名
// 4時: 1名 (入店する人のみカウント)
//
int naive_solution(int &C, int &T, vector<int> &S, vector<int> &E) {
  vector<int> table(T);

  for (int i = 0; i < C; i++) {
    for (int j = S.at(i); j < E.at(i); j++) {
      table.at(j)++;
    }
  }

  int M = 0;
  for (int i = 0; i < T; i++) {
    M = max(M, table.at(i));
  }
  return M;
}

// いもす法による解法 (1次元0次いもす法)
// 計算量: O(C + T)
//
// ### データ例
//
// 1人目: 1時〜4時
// 2人目: 3時〜5時
//
//                1  2  3  4  5
// ----------------------------
//        1人目: +1       -1
//        2人目:       +1    -1
// ----------------------------
//   入出店処理: +1 +0 +1 -1 -1
// ----------------------------
// シミュレート: +1 +1 +2 +1  0
//
int imos_method(int &C, int &T, vector<int> &S, vector<int> &E) {
  vector<int> table(T);

  // 記録
  for (int i = 0; i < C; i++) {
    table.at(S.at(i))++; // 入店処理
    table.at(E.at(i))--; // 出店処理
  }
  // シミュレート
  for (int i = 1; i < T; i++) {
    table.at(i) = table.at(i) + table.at(i - 1);
  }
  // 最大値を調べる
  int M = 0;
  for (int i = 0; i < T; i++) {
    M = max(M, table.at(i));
  }
  return M;
}

int main() {
  // C : 喫茶店を訪れたお客さんの数 (0 <= C <= 10^3)
  int C = 2;
  // T : 最大時刻
  int T = 24;
  // Si: お客さん i の入店時刻
  vector<int> S = {1, 3};
  // Ei: お客さん i の出店時刻 (0 <= Si < Ei <= T)
  vector<int> E = {4, 5};
  // M : 同時刻にお店にいた客の数の最大値

  int M1 = naive_solution(C, T, S, E);
  cout << M1 << endl;

  int M2 = imos_method(C, T, S, E);
  cout << M2 << endl;
  return 0;
}
