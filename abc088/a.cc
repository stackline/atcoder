#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  int r = N % 500;
  if (r <= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
