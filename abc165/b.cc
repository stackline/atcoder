#include <bits/stdc++.h>
using namespace std;

int main() {
  long x;
  cin >> x;

  long a = 100;
  int year = 0;
  while (a < x) {
    year++;
    a = a * 1.01;
  }
  cout << year << endl;
  return 0;
}
