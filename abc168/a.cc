#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int rest = n % 10;
  if (rest == 2 || rest == 4 || rest == 5 || rest == 7 || rest == 9) {
    cout << "hon" << endl;
  }
  if (rest == 0 || rest == 1 || rest == 6 || rest == 8) {
    cout << "pon" << endl;
  }
  if (rest == 3) {
    cout << "bon" << endl;
  }
  return 0;
}
