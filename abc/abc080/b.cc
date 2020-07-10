#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int sum = 0;
  int NC = N;
  for (int i = 8; i >= 0; i--) {
    int a = pow(10, (i));
    int b = NC / a;
    sum += b;
    NC = NC - (a * b);
  }
  cout << (((N % sum) == 0) ? "Yes" : "No") << endl;
  return 0;
}
