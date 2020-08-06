#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int insertion_sort(vector<int> &A, int n, int g) {
  int cnt = 0;

  for (int i = g; i < n; i++) {
    int v = A.at(i);
    int j = i - g;

    while (j >= 0 && A.at(j) > v) {
      A.at(j+g) = A.at(j);
      j = j-g;
      cnt++;
    }

    A.at(j+g) = v;
  }

  return cnt;
}

void shell_sort(vector<int> A, int n) {
  vector<int> G;
  int g = 1;
  // n=1 の配列についても、g=1 で通常の挿入ソートを行うように、必ず G[0]=1 がセットされるようにする
  //
  // NOTE: (g < n) の条件のみだと、1<1 という判定で G[0]=1 がセットされなくなる
  while (g == 1 || g < n) {
    G.push_back(g);
    g = 3 * g + 1;
  }

  // 1行目 : 整数m
  int m = (int) G.size();
  cout << m << endl;

  // 2行目 : m個の整数Gi
  // 1, 4, 13, ... という数列を ..., 13, 4, 1 に並べ替える
  sort(G.rbegin(), G.rend());
  for (int i = 0; i < m; i++) {
    if (i > 0) { cout << " "; }
    cout << G.at(i);
  }
  cout << endl;

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += insertion_sort(A, n, G.at(i));
  }

  // 3行目 : Gを用いた場合のプログラムが終了した直後のcnt
  cout << cnt << endl;

  // 4行目 : ソート後のA
  for (int i = 0; i < n; i++) {
    cout << A.at(i) << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A.at(i);
  }

  shell_sort(A, n);
  return 0;
}
