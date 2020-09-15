#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".
}

int main() {
  init();
  int n;
  cin >> n;
  cout << 1-n << "\n";
  return 0;
}
