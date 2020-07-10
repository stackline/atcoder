#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int t = N, c = 0;
  // // 148
  // c += t % 10; // 8
  // t = t / 10; // 14
  // // 14
  // c += t % 10; // 4
  // t = t / 10; // 1
  // // 1
  // c += t % 10; // 1
  // t = t / 10; // 0
  while (t > 0) {
    c += t % 10;
    t = t / 10;
  }
  cout << ((N % c == 0) ? "Yes" : "No") << endl;
}
