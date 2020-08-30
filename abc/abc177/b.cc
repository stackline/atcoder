#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;

  int s_size = s.size();
  int t_size = t.size();

  int ans = s_size;
  for (int i = 0; i < (s_size - t_size + 1); i++) {
    int cnt = 0;
    for (int j = 0; j < t_size; j++) {
      if (s.at(i+j) != t.at(j)) {
        cnt++;
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
