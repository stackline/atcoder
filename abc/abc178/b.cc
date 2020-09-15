#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr); // cin 時に cout を flush しない
  // cout << "hogehoge" << '\n';  // endl は改行後に flush するので、改行のみとする
  // ios::sync_with_stdio(false); // cin/cout と scanf/printf が混在する場合は注意
}

int main() {
  init();

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll ans = -1e9 * 1e9;
  ans = max(ans, a * c);
  ans = max(ans, a * d);
  ans = max(ans, b * c);
  ans = max(ans, b * d);
  cout << ans << endl;

  return 0;
}
