#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while(1) {
    char x[1000];
    cin >> x;

    if (x[0] == '0') { break; }

    int sum = 0;
    for (int i = 0; x[i] != '\0' ; i++) {
      sum += x[i] - '0';
    }

    cout << sum << endl;
  }

  return 0;
}
