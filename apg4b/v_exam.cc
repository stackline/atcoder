#include <bits/stdc++.h>
using namespace std;

int calc_time(vector<int> p, int i) {
  int parent = p[i];
  if (parent == 0) {
    return 1;
  }

  return calc_time(p, parent - 1) + 1;
}

int main() {
  int n;
  cin >> n;

  vector<int> p(n-1);
  for (int i = 0; i < (n - 1); i++) {
    cin >> p[i];
  }

  int max = 0;
  for (int i = 0; i < (n - 1); i++) {
    int t = calc_time(p, i);
    if (t > max) {
      max = t;
    }
  }

  cout << max << endl;
  return 0;
}
