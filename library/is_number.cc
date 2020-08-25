#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_number(string s) {
  auto condition = [](char c) {
    return isdigit(c);
  };
  return all_of(s.begin(), s.end(), condition);
}

int main() {
  vector<string> v = {"abc", "123"};

  for (int i = 0; i < (int)v.size(); i++) {
    string s = v.at(i);
    cout << s << " is ";
    cout << (is_number(s) ? "number" : "not number") << "." << endl;
  }

  return 0;
}
