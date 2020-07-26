#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int t_point = 0;
  int h_point = 0;
  for (int i = 0; i < n; i++) {
    string t_string, h_string;
    cin >> t_string >> h_string;

    if (t_string > h_string) {
      t_point += 3;
    } else if (t_string < h_string) {
      h_point += 3;
    } else {
      t_point += 1;
      h_point += 1;
    }
  }

  cout << t_point << " " << h_point << endl;
  return 0;
}
