#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int popcount(int x) {
  if (x == 0) { return 0; }
  return popcount(x >> 1) + (x & 1);
}

int main() {
  int a = popcount(8);
  cout << "popcount of  8 (1000) : " << a << endl;

  int b = popcount(15);
  cout << "popcount of 15 (1111) : " << b << endl;
  return 0;
}
