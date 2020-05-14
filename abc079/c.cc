#include <bits/stdc++.h>
#include <sstream>
using namespace std;

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
  stringstream ss;
  int num;
  ss << s[i];
  ss >> num;

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

  stringstream ss;
  int sum;
  ss << s[0];
  ss >> sum;

  formula = calc(s, formula, sum, 1);

  cout << formula << endl;
  return 0;
}
