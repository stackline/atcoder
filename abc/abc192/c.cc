#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll k, ll cnt) {

  cout << "n: " << n;
  cout << ", k: " << k;
  cout << ", cnt: " << cnt << endl;
  // ベースケース
  if (cnt == k) {
    return n;
  }

  // 再帰ステップ
  string s1 = to_string(n);
  sort(s1.rbegin(), s1.rend());
  ll s1_num = stoll(s1);

  string s2 = to_string(n);
  sort(s2.begin(), s2.end());
  ll s2_num = stoll(s2);

  return f((s1_num - s2_num), k, cnt + 1);
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, k;
  cin >> n >> k;

  ll current = n;
  for (int i = 0; i < k; i++) {
    string s1 = to_string(current);
    sort(s1.rbegin(), s1.rend());
    ll s1_num = stoll(s1);

    string s2 = to_string(current);
    sort(s2.begin(), s2.end());
    ll s2_num = stoll(s2);

    ll next = s1_num - s2_num;
    current = next;
  }

  // ll ans = f(n, k, 0);
  // cout << ans << endl;
  cout << current << endl;
  return 0;
}
