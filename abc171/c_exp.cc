#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string recursive(ll n) {
  // ベースケース
  if (n == 0) {
    return "";
  }

  // 再帰ステップ
  n--; // 0-indexed
  ll quotient = n / 26;
  ll remainder = n % 26;
  return recursive(quotient) + static_cast<char>('a' + remainder);
}

int main() {
  ll n;
  cin >> n;

  string ans = recursive(n);
  cout << ans << endl;
  return 0;
}
