#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  // クイックソートがO(N logN)
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  ll ans = 0;
  queue<ll> q;
  // 一人目が到着
  // 一人目の心地よさを享受可能な座席は1つのみのため、キューに1座席追加
  q.push(v.at(0));
  for (int i = 1; i < n; i++) {
    // 1人到着したため、座席を1つ消費する
    ans += q.front();
    q.pop();

    // 二人目以降が到着すると、両隣に座席ができる
    // 心地よさは二座席分享受できるため、キューに2座席分追加
    ll num = v.at(i);
    q.push(num);
    q.push(num);
  }

  cout << ans << endl;
  return 0;
}
