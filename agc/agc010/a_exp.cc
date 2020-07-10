#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    sum += num;
  }

  cout << (sum % 2 == 0 ? "YES" : "NO") << endl;
  return 0;
}
