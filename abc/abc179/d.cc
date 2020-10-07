#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll search(int n) {
  // ベースケース（マス1に到着）
  if (n == 1) {
    return 1;
  }

  // 再起ステップ
  return n;
}

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  // const int mod = 998244353;

  // n: マス目の数
  // k: 区間の数
  int n, k;
  cin >> n >> k;

  // v: 区間[l, r]
  // s: 区間の和集合
  // vector<pair<int, int>> v(k);
  set<int> s;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    // v.at(i) = make_pair(l, r);
    for (int i = l; i <= r; i++) {
      s.insert(i);
    }
  }

  // スタートから探索を開始すると探索の幅が広がるので、
  // ゴールから戻る形で探索を開始する。
  //
  // 全探索で書いて、DPに持っていく

  ll ans = search(n);
  cout << ans << endl;

#ifndef ONLINE_JUDGE
  cout << "size: " << s.size() << '\n';
  cout << "elem: ";
  for (int value : s) { cout << value << " "; }
  cout << '\n';
#endif
  return 0;
}
