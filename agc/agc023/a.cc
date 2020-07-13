#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calcCombination(ll n, ll r){
    ll result = 1;
    for (ll i = 1; i <= r; i++) {
      result = result * (n + 1 - i) / i;
    }
    return result;
}

// O(N + N + (N + 1) + (N + 1) * logN + N * 2)
// O(5N + 2 * N logN)
// O(N logN)
int main() {
  int N;
  cin >> N;

  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  // 累積和の作成
  vector<ll> s(N + 1, 0);
  for (int i = 0; i < N; i++) {
    s.at(i + 1) = s.at(i) + a.at(i);
  }

#ifndef ONLINE_JUDGE
  for (int i = 0; i < N + 1; i++) {
    cout << i << ": " << s.at(i) << endl;
  }
#endif

#ifndef ONLINE_JUDGE
  cout << "# debug" << endl;
#endif
  // 累積和の集計
  map<ll, ll> mp;
  for (int i = 0; i < N + 1; i++) {
    ll sum = s.at(i);
    mp[sum]++;
  }

  ll ans = 0;
  for (auto i = mp.begin(); i != mp.end(); i++) {
    // 累積和の中で、特定の値の発生回数
    ll n = i->second;
    ll num_of_combinations = calcCombination(n, 2);
    ans += num_of_combinations;
  }

  cout << ans << endl;
  return 0;
}
