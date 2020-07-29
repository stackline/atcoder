#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// * i学期の評点L(i)
//   * N=10, i=4, K=3 の場合
//     * 2, 3, 4
//   * N=10, i=5, K=3 の場合
//     * 3, 4, 5
//   * L(i) = A[i-K+1], A[i-K+2], A[i-K+3] = A[i]
// * i-1学期の評点L(i-1)
//   * L(i-1) = A[i-K], A[i-K+1], A[i-K+2] = A[i-1]
//
// ### i学期の評点が i-1 学期の評点より高い
//
// L(i)
// ------- > 1
// L(i-1)
//
// ### LをAの総和で表すと以下になる
//
// A[i-K+1], A[i-K+2], A[i-K+3], ... , A[i]
// ---------------------------------------- > 1
// A[i-K], A[i-K+1], A[i-K+2], ... , A[i-1]
//
//     A[i]
// <=> ------ > 1
//     A[i-K]
//
// <=> A[i] > A[i-K]
//
int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  for (int i = K; i < N; i++) {
    int current = A.at(i);
    int before  = A.at(i - K);

    if (current > before) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
