#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> s(n + 1, 0);
  for (int i = 0; i < k; i++) {
    int d;
    cin >> d;

    for (int j = 0; j < d; j++) {
      int a;
      cin >> a;
      s[a]++;
    }
  }

  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 0) {
      num++;
    }
  }

  cout << num << endl;
  return 0;
}
