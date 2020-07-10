#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    mp[num]++;
  }

  if ((int)mp.size() <= K) {
    cout << 0 << endl;
    return 0;
  }


  vector<int> v;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    v.push_back(itr->second);
  }

  sort(v.begin(), v.end());

  int ans = 0;
  int pattern = (int)v.size();
  for (int i = 0; i < (int)v.size(); i++) {
    ans += v.at(i);
    pattern--;
    if (pattern <= K) {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
