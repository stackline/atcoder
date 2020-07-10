#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> L(2);
  L.at(0) = 2;
  L.at(1) = 1;

  if (N >= 2) {
    for (int i = 2; i <= N; i++) {
      long long num = L.at(i - 1) + L.at(i - 2);
      L.push_back(num);
    }
  }
  cout << L.at(N) << endl;

  return 0;
}
