#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i =0; i < (int)(n); i++)

int main() {
  int a, b;
  cin >> a >> b;

  cout << "A:";
  rep(i, a) {
    cout << "]";
  }
  cout << endl;

  cout << "B:";
  rep(i, b) {
    cout << "]";
  }
  cout << endl;

  return 0;
}
