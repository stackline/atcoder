#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 O(N**2)
int selection_sort(vector<int> &A, int N) {
  int counter = 0;
  // i=0 の時
  //   i>=1 の要素について、i=0 の値より小さい値が複数存在する場合、その値の中で最も小さい値の要素番号をピックアップする。
  //   i=0 の値と i=minj の値を交換する。
  //   これで i=0 には、最も小さい値がセットされていることになる。
  //   つまり、i=0 はソート済みの部分列となる。
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A.at(j) < A.at(minj)) {
        minj = j;
      }
    }

    // i=x の時、対象の要素が i>x より最も小さい値の場合、i=minj となる。
    // この場合は交換する必要がないので swap しない。
    if (minj != i) {
      swap(A.at(i), A.at(minj));
      counter++;
    }
  }

  return counter;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int counter = selection_sort(A, N);

  for (int i = 0; i < N; i++) {
    cout << A.at(i);
    if (i < N-1) {
      cout << " ";
    }
  }
  cout << endl;

  cout << counter << endl;
  return 0;
}
