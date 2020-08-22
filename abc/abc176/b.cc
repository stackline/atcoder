#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < (int)n.size(); i++) {
    int num = n.at(i) - '0';
    sum += num;
  }

  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
