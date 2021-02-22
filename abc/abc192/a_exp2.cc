#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int x;
  cin >> x;
  int next = (x / 100) * 100 + 100;
  cout << next - x << endl;
  return 0;
}
