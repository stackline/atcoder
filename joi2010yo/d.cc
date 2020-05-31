#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; // 4 <= n <= 10
  int k; // 2 <= k <= 4
  cin >> n >> k;

  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  sort(v.begin(), v.end());
  set<string> s;
  do {
    string a;
    for (int i = 0; i < k; i++) {
      a += v.at(i);
    }
    s.insert(a);
  } while (next_permutation(v.begin(), v.end()));

  cout << s.size() << endl;
  return 0;
}
