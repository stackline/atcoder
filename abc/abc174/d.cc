#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  int counter = 0;
  while (1) {
    int w_pos = (int)s.find_first_of('W');
    int r_pos = (int)s.find_last_of('R');

    if (w_pos == (int)string::npos || r_pos == (int)string::npos) {
      break;
    }

    if (w_pos < r_pos) {
      swap(s.at(w_pos), s.at(r_pos));
      counter++;
    } else {
      break;
    }
  }

  cout << counter << endl;
  return 0;
}
