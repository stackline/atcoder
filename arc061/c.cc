#include <bits/stdc++.h>
using namespace std;

void build_patterns(string &s, vector<string> &patterns, string pattern) {
  // ベースケース
  if (pattern.size() == s.size() - 1) {
    patterns.push_back(pattern);
    return;
  }

  // 再帰ステップ
  build_patterns(s, patterns, pattern + "o");
  build_patterns(s, patterns, pattern + "x");
}

vector<string> split(const string &src, const char &delim) {
  vector<string> vec;
  string::size_type len = src.length();
  string::size_type n = 0;

  for (string::size_type i = 0; n < len; i = n + 1) {
    n = src.find_first_of(delim, i);
    if (n == string::npos) {
      n = len;
    }
    vec.push_back(src.substr(i, n - i));
  }

  return vec;
}

int main() {
  string s;
  cin >> s;
  // s = "125";

  // build patterns
  vector<string> patterns;
  build_patterns(s, patterns, "o");
  build_patterns(s, patterns, "x");

  // build formulas
  vector<string> formulas;
  for (auto pattern : patterns) {
    string formula = "";
    for (int i = 0; i < (int)s.size(); i++) {
      formula += s.at(i);
      if (i < (int)pattern.size() && pattern.at(i) == 'o') {
        formula += '+';
      }
    }
    formulas.push_back(formula);
  }

  long ans = 0;
  for (int i = 0; i < (int)patterns.size(); i++) {
    vector<string> vec = split(formulas[i], '+');
    for (string num : vec) {
      ans += stol(num);
    }
  }
  cout << ans << endl;
  return 0;
}
