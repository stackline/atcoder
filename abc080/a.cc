#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >>N>>A>>B;
  int p1 = A * N;
  if (p1 < B) {
    cout << p1 << endl;
  } else {
    cout << B << endl;
  }
  return 0;
}
