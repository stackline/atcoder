#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 時間計算量: O(n + (max|Ai|)**2)
//
//   n
//     入力値の受け取り。
//
//   (max|Ai|)**2
//     max(|Ai|) で、探索する値の幅を決定する。
//       10 -20 30 -40 の場合、-40 〜 40 を探索する。
//       |Ai| <= 200 より、最大で -200 〜 200 になる。
//     決定した幅の値について、全探索する。
//       最大で |Ai| = 200 の時に 200**2 = 40_000 になる。
//
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  // -200 〜 200 までの 401 件の値をカウントする
  vector<ll> cnt(401);
  for (int i = 0; i < n; i++) {
    // -200 を cnt の要素番号 0 で管理する
    ll a_idx = a.at(i) + 200;
    cnt.at(a_idx)++;
  }

  // 入力データ例: 2 8 4 2
  // cnt
  //   cnt[202] = 2
  //   cnt[204] = 1
  //   cnt[208] = 1
  //
  // 2 と 8 の組み合わせの数は 2 * 1 = 2種類
  //   (a0の2, 8)
  //   (a3の2, 8)
  // 2 と 4 の組み合わせの数は 2 * 1 = 2種類
  //   (a0の2, 4)
  //   (a3の2, 4)
  // 2 と 2 の組み合わせは abs(2 - 2) = 0 となるため、加算されない
  //
  ll ans = 0;
  for (int i = 0; i < (int)cnt.size(); i++) {
    for (int j = i + 1; j < (int)cnt.size(); j++) {
      ll ai = i - 200;
      ll aj = j - 200;
      // if (cnt.at(i) > 0 && cnt.at(j) > 0) {
      //   cout << "i:  " << i << endl;
      //   cout << "j:  " << j << endl;
      //   cout << "ai: " << ai << endl;
      //   cout << "aj: " << aj << endl;
      //   cout << "cnt.at(i): " << cnt.at(i) << endl;
      //   cout << "cnt.at(j): " << cnt.at(j) << endl;
      // }
      ans += cnt.at(i) * cnt.at(j) * (ai * ai + aj * aj + ai * aj * -2);
    }
  }

  cout << ans << endl;
  return 0;
}
