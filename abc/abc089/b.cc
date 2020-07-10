#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool hasYellow = false;

  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;

    if (S == "Y") {
      hasYellow = true;
      break;
    }
  }

  cout << ((hasYellow == true) ? "Four" : "Three") << endl;
  return 0;
}
