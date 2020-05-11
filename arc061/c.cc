#include <bits/stdc++.h>
using namespace std;

long dfs_calc(string &s) {
  int len = s.length();
  long sum = stol(s);

  for (int i = 1; i < len; i++) {
    string left = s.substr(0, i);
    sum += stol(left) * pow(2, len - i - 1);
    string right = s.substr(i, len - i);
    sum += dfs_calc(right);
  }

  return sum;
}

int main() {
  string s;
  cin >> s;
  // s = "9999999999";

  long sum = dfs_calc(s);
  cout << sum << endl;
  return 0;
}
