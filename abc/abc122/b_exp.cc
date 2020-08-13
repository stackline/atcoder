#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int size = (int)s.size();
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      bool is_acgt_only = true;

      for (int k = i; k <= j; k++) {
        char c = s.at(k);
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
          is_acgt_only = false;
        }
      }

      if (is_acgt_only) {
        ans = max(ans, (j-i+1));
      }
    }
  }

  cout << ans << endl;
  return 0;
}
