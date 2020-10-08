#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// s: 区間の和集合
// n: 最大のマス番号
// current: 現在のマス番号
ll full_search(set<int> &s, int &n, int current) {
  // ベースケース（ゴールに到着）
  if (current == n) {
    return 1;
  }

  // 再起ステップ
  ll cnt = 0;
  for (auto i : s) {
    // nマス以内であれば、探索を進める。
    // ゴールに到達した移動方法があれば、cnt を +1 する。
    if ((current+i <= n)) {
      cnt = cnt + full_search(s, n, current + i);
    }
  }

  return cnt;
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
  set<int> s;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      s.insert(i);
    }
  }

  // 全探索
  ll ans = full_search(s, n, 1);

  // TODO: 全探索は TLE するので、メモ探索かDPに書き直す
  // TODO: mod を取る
  cout << ans << endl;

#ifndef ONLINE_JUDGE
  cout << "size: " << s.size() << '\n';
  cout << "elem: ";
  for (int value : s) { cout << value << " "; }
  cout << '\n';
#endif
  return 0;
}
