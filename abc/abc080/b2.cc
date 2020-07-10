#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int fx = 0;
  int num = N;
  while (num > 0) {
    fx += num % 10;
    num = num / 10;
  }

  if (N % fx == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
