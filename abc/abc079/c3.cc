#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> bs(tmp);

    int sum = s.at(0) - '0';
    string formula = to_string(sum);
    for (int i = 0; i < (int)s.size() - 1; i++) {
      int n = s.at(i + 1) - '0';
      string sign;

      // 加算
      if (bs.test(i) == 1) {
        sum += n;
        sign = "+";
      // 減算
      } else {
        sum -= n;
        sign = "-";
      }
      formula += sign + to_string(n);
    }

    if (sum == 7) {
      cout << formula << "=7" << endl;
      return 0;
    }
  }

  return 0;
}
