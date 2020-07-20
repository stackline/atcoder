#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int S;
  cin >> S;

  int hours = S / (60 * 60);
  S = S - hours * (60 * 60);
  int minutes = S / 60;
  int seconds = S - minutes * 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;
  return 0;
}
