#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // 累積和
  vector<int> white_s(n+1, 0);
  vector<int> red_s(n+1, 0);
  for (int i = 0; i < n; i++) {
    char c = s.at(i);
    if (c == 'W') {
      white_s.at(i+1) = white_s.at(i) + 1;
      red_s.at(i+1)   = red_s.at(i);
    } else {
      white_s.at(i+1) = white_s.at(i);
      red_s.at(i+1)   = red_s.at(i) + 1;
    }
  }

  // n=8
  // c= W R W W|R W R R
  //   0 1 2 3 4 5 6 7 8
  int ans = n;
  for (int i = 0; i < n+1; i++) {
    int left_w = white_s.at(i);
    int right_r = red_s.at(n) - red_s.at(i);
    int op_count = max(left_w, right_r);
    ans = min(ans, op_count);
  }

  cout << ans << endl;
  return 0;
}
