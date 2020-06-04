#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;

  int rest = n % 500;
  cout << (rest <= a ? "Yes" : "No") << endl;
  return 0;
}
