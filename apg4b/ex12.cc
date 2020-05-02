#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int num = 1;
  int size = S.size();
  for (int i = 1; i < size; i++) {
    char op = S.at(i);
    if (op == '+') {
      num++;
    } else if (op == '-') {
      num--;
    } else {
      continue;
    }
  }
  cout << num << endl;
  return 0;
}
