#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  // A 赤
  // B 緑
  // C 青
  //
  // 1. 緑 > 赤
  // 2. 青 > 緑
  // 青 > 緑 > 赤

  int counter = 0;
  while (B <= A) {
    B = B * 2;
    counter++;
  }

  while (C <= B) {
    C = C * 2;
    counter++;
  }

  if (counter <= K) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
