#include <bits/stdc++.h>
#include <iomanip> // for lint (use of undeclared identifier 'setprecision')
using namespace std;
using ll = long long;

char itoc(int i) {
  if (i >= 0 && i <= 9) {
    return '0' + i;
  }
  throw invalid_argument("itoc argument is not between 0 and 9.");
}

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  throw invalid_argument("ctoi argument is not between '0' and '9'.");
}

int main() {
  int a, b;
  cin >> a >> b;

  // Bit traverse
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    cout << s << endl;
  }
  return 0;
}
