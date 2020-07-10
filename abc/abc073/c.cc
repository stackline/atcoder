#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (mp.count(a)) {
      mp.erase(a);
    } else {
      mp[a] = 1;
    }
  }

  cout << mp.size() << endl;
  return 0;
}
