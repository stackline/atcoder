#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char itoc(int i) {
  if (i >= 0 && i <= 9) {
    return '0' + i;
  }
  throw invalid_argument("itoc argument is not between 0 and 9.");
}

int main() {
  string s = "a:";
  int n = 1;

  // cout << s + n << endl;
  //
  // error: no match for 'operator+' (operand types are 'std::string' {aka 'std::__cxx11::basic_string<char>'} and 'int')
  // |   cout << s + n << endl;
  // |           ~ ^ ~
  // |           |   |
  // |           |   int
  // |           std::string {aka std::__cxx11::basic_string<char>}

  cout << s + itoc(n) << endl;
  // --> a:1

  return 0;
}
