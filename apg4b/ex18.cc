#include <bits/stdc++.h>
using namespace std;

int main() {
  // n : person
  // m : game
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<char>> chart(N, vector<char>(N, '-'));
  for (int i = 0; i < M; i++) {
    int winner = A.at(i) - 1;
    int loser = B.at(i) - 1;
    chart[winner][loser] = 'o';
    chart[loser][winner] = 'x';
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << chart[i][j];
      if (j < (N - 1)) {
        cout << " ";
      }
    }
    cout << endl;
  }
}

