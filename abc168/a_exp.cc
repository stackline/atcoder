#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  switch(n % 10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9: cout << "hon" << endl;
            break;
    case 0:
    case 1:
    case 6:
    case 8: cout << "pon" << endl;
            break;
    case 3: cout << "bon" << endl;
            break;
  }
  return 0;
}
