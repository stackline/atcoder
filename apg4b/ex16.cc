#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  int before = 0;
  for (int current : data) {
    if (before == current) {
      cout << "YES" << endl;
      return 0;
    }
    before = current;
  }

  cout << "NO" << endl;
  return 0;
}
