#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  vector<int> d(x, 0);

  for (int i = 0; i < x; i++) {
    cin >> d[i];
  }

  sort(d.rbegin(), d.rend());

  int num = 0;
  int current = 101;
  for (int i = 0; i < x; i++) {
    if (d[i] < current) {
      current = d[i];
      num++;
    }
  }
  cout << num << endl;
  return 0;
}
