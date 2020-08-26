#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> q(n);
  for (int i = 0; i < n; i++) { cin >> p.at(i); }
  for (int i = 0; i < n; i++) { cin >> q.at(i); }

  vector<int> order(n);
  for (int i = 0; i < n; i++) { order.at(i) = i+1; }

  map<vector<int>, int> mp;
  do {
    mp[order] = mp.size();
  } while (next_permutation(order.begin(), order.end()));

  cout << abs(mp.at(p) - mp.at(q)) << endl;
  return 0;
}
