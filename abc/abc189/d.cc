#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memoize(vector<vector<bool>> &done, vector<vector<ll>> &memo,
           vector<string> s, int i, bool flag) {
  // ベースケース
  if (i == (int)s.size()) {
    if (flag == true) {
      return 1;
    } else {
      return 0;
    }
  }
  // ----- メモ化 -----
  if (done.at(i).at(flag)) {
    return memo.at(i).at(flag);
  }
  // ----- メモ化 -----

  // 再帰ステップ
  ll sum = 0;
  if (s.at(i) == "AND") {
    sum += memoize(done, memo, s, i + 1, (flag && true));
    sum += memoize(done, memo, s, i + 1, (flag && false));
  } else {
    sum += memoize(done, memo, s, i + 1, (flag || true));
    sum += memoize(done, memo, s, i + 1, (flag || false));
  }

  // ----- メモ化 -----
  done.at(i).at(flag) = true;
  memo.at(i).at(flag) = sum;
  // ----- メモ化 -----
  return sum;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }

  // ll x = search(s, 0, true);
  // ll y = search(s, 0, false);
  vector<vector<bool>> done(n, vector<bool>(2, false));
  vector<vector<ll>> memo(n, vector<ll>(2, 0));
  ll x = memoize(done, memo, s, 0, true);
  ll y = memoize(done, memo, s, 0, false);
  cout << (x + y) << endl;
  return 0;
}
