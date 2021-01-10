#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll imos(ll n, ll prime_c, vector<ll> a, vector<ll> b, vector<ll> c) {
  // vector<ll> table(10e9+1) でシミュレートすると、TLEするため、
  // データ構造は map を使用する。
  //
  // map のキーは ai と bi である。
  // N <= (2 * 10e5) より、キーの最大の数は 2 * 2 * 1-e5 である。
  map<ll, ll> table;

  // 記録
  for (ll i = 0; i < n; i++) {
    table[a.at(i)] += c.at(i);     // 利用開始
    table[b.at(i) + 1] -= c.at(i); // 利用終了
  }

  // シミュレート
  int key_prev = 0;
  for (auto itr = table.begin(); itr != table.end(); itr++) {
    if (itr == table.begin()) {
      key_prev = itr->first;
    } else {
      itr->second = itr->second + table.at(key_prev);
      key_prev = itr->first;
    }
  }

  // map のキーは long long 型であり、昇順にソートされている。
  // time 変数にキーを順番に詰めていく。
  // これは ai と bi を sort して distinct した集合である。
  vector<ll> time;
  for (auto itr = table.begin(); itr != table.end(); itr++) {
    time.push_back(itr->first);
  }

  // 費用を算出する
  //
  // 料金が一定である期間 t1 〜 t2 について、以下のどちらが安いか比較する。
  //
  // (a) プライムを利用した際の料金
  // (b) t1 〜 t2 で利用したサービスの料金を個別に支払った際の合算
  //
  // 上記2パターンの内、より安くなる支払い方法で支払う。
  // t1 〜 t2 の期間、決定した方法で支払いを続けるため、
  // 対象期間の料金は以下となる。
  //
  // * min((a), (b)) * (t2 - t1)
  //
  ll ans = 0;
  for (int i = 1; i < (int)time.size(); i++) {
    ll t1 = time.at(i - 1);
    ll t2 = time.at(i);
    ll cost = min(table.at(t1), prime_c);
    // printf("t1: %lld, t2: %lld, table.at(t1): %lld, prime_c:%lld\n", t1, t2,
    //        table.at(t1), prime_c);
    ans += cost * (t2 - t1);
  }

  return ans;
}

int main() {
  cin.tie(nullptr);

  ll n, prime_c;
  cin >> n >> prime_c;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  ll ans = imos(n, prime_c, a, b, c);
  cout << ans << endl;
  return 0;
}
