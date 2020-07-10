#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  throw invalid_argument("ctoi argument is not between '0' and '9'.");
}

int main() {
  string a;
  cin >> a;

  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> bs(tmp);
    string formula;
    formula.push_back(a.at(0));
    int sum = ctoi(a.at(0));

    for (int i = 0; i < ((int)a.size() - 1); i++) {
      // 1の場合は加算、0の場合は減算とする
      if (bs.test(i)) {
        sum += ctoi(a.at(i + 1));
        formula.push_back('+');
        formula.push_back(a.at(i + 1));
      } else {
        sum -= ctoi(a.at(i + 1));
        formula.push_back('-');
        formula.push_back(a.at(i + 1));
      }
    }
    if (sum == 7) {
      cout << formula << "=7" << endl;
      return 0;
    }
  }

  return 0;
}
