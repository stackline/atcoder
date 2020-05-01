#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i =0; i < (int)(n); i++)

int main() {
  int N, A;
  cin >> N >> A;

  string op;
  int B;

  rep(i, N) {
    cin >> op >> B;
    if (op == "+") {
      A += B;
    }
    if (op == "-") {
      A -= B;
    }
    if (op == "*") {
      A *= B;
    }
    if (op == "/") {
      if (B == 0) {
        cout << "error" << endl;
        break;
      } else {
        A /= B;
      }
    }

    cout << (i + 1) << ":" << A << endl;
  }
  return 0;
}
