#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  char alpha;
  cin >> alpha;

  int num = alpha - '0';
  if (num >= 'a' - '0' && num <= 'z' - '0') {
    cout << 'a' << endl;
  }
  if (num >= 'A' - '0' && num <= 'Z' - '0') {
    cout << 'A' << endl;
  }

  return 0;
}
