#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

string calc(string &s, string formula, int sum, int i) {
  // ベースケース
  if (i == (int) s.size()) {
    if (sum == 7) {
      return formula + '=' + to_string(sum);
    } else {
      return "";
    }
  }
  // 再帰ステップ
  int num = ctoi(s[i]);

  string calculated;
  // 加算
  calculated = calc(s, formula + '+' + s[i], sum + num, i + 1);
  if (calculated == "") {
    // だめなら減算
    calculated = calc(s, formula + '-' + s[i], sum - num, i + 1);
  }

  return calculated;
}

int main() {
  string s;
  cin >> s;

  string formula;
  formula.push_back(s[0]);
  int sum = ctoi(s[0]);

  formula = calc(s, formula, sum, 1);

  cout << formula << endl;
  return 0;
}
