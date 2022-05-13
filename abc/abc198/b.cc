#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string n;
  cin >> n;

  if ((int)n.size() == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  reverse(n.begin(), n.end());
  // cout << n << endl;
  string n2 = "";
  bool zero_end_flag = false;
  for (int i = 0; i < (int)n.size(); i++) {
    if (n.at(i) == '0' && zero_end_flag == false) {
      continue;
    }
    zero_end_flag = true;
    n2 += n.at(i);
  }
  // cout << n2 << endl;

  bool can = true;
  int left = 0;
  int right = n2.size() - 1;
  while (1) {
    if (n2.at(left) != n2.at(right)) {
      can = false;
    }
    if (right - left <= 2) {
      break;
    }
    left++;
    right--;
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
