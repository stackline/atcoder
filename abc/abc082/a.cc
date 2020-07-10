#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int i = (a + b) / 2;
  int r = (a + b) % 2;

  cout << (i + r) << endl;
}
