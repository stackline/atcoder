#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b = a / 100;
  int c = (a - (b * 100)) / 10;
  int d = (a - (b * 100) - (c * 10)) / 1;
  cout << (b + c + d) << endl;
}
