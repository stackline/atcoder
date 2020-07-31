#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  ll current_money = 1000;
  for (int i = 0; i < N - 1; i++) {
    // cout << current_money << endl;
    int today = A.at(i);
    int tomorrow = A.at(i + 1);
    if (tomorrow > today) {
      ll stock = current_money / today;
      current_money = current_money + (tomorrow - today) * stock;
    }
  }

  cout << current_money << endl;
  return 0;
}
