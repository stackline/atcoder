#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Y;
  cin >> N >> Y;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= (N - i); j++) {
      int k = N - (i + j);
      int price = i * 10000 + j * 5000 + k * 1000;
      if (price == Y) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}
