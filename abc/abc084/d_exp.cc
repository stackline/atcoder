#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int lim = 100000;
  vector<bool> f(100001, false);
  vector<int> c(100002, 0);

  // エラトステネスの櫛で素数を洗い出す
  for (int i = 2; i <= lim; i++) {
    if (f.at(i) == false) {
      // 初回であれば2より大きい2の倍数、つまり4から始まる
      // そこから2の倍数でループを回す
      for (int j = i + i; j <= lim; j = j + i) {
        f.at(j) = true;
      }
    }
  }

  // 奇数について、「2017に似た数」の条件を満たす場合は、カウントを +1 する
  // 偶数は (N + 1) / 2 で割り切れないため、考慮外とする
  for (int i = 3; i <= lim; i = i + 2) {
    // ともに素数の場合
    if (f.at(i) == false && f.at((i + 1) / 2) == false) {
      c.at(i)++;
    }
  }

  // 累積和にする
  for (int i = 3; i <= lim; i++) {
    c.at(i) = c.at(i) + c.at(i - 1);
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    // 3〜7 の場合は、7までの合計から2までの合計を引く
    cout << (c.at(r) - c.at(l - 1)) << endl;
  }

  return 0;
}
