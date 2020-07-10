#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int a = n / 1000;
  int b = n % 1000;

  if (b > 0) {
    a++;
  }

  cout << ((a * 1000) - n) << endl;
  return 0;
}
