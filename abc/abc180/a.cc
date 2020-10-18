#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and
  // "scanf/printf".

  int n, a, b;
  cin >> n >> a >> b;

  cout << (n - a + b) << endl;
  return 0;
}
