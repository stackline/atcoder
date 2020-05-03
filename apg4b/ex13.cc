#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) { cin >> a.at(i); }

  int sum = 0;
  for (int i = 0; i < n; i++) { sum += a.at(i); }

  int avg = sum / n;

  for (int i = 0; i < n; i++) {
    int num = a.at(i);
    int diff = num - avg;
    if (diff < 0) {
      cout << diff * -1 << endl;
    } else {
      cout << diff << endl;
    }
  }
  return 0;
}
