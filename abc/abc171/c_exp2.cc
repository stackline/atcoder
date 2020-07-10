#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  int len = 0;
  ll sum = 0;
  ll base = 0;
  for (int i = 1; i < 12; i++) {
    ll product = 1;
    for (int j = 0; j < i; j++) {
      product = product * 26;
    }

    sum = sum + product;
    if (N <= sum) {
      len = i;
      base = sum - product;
      break;
    }
  }

  // 例えば N = 704 は aab である。
  // N = 704 から以下の値を求める。
  // ・文字列の長さ len = 3
  // ・文字列の長さ3文字の開始より前の番号 base = 702
  // ・703 を0番目と捉えて、N が何番目の数値かを確認する
  // 　・704 の場合は、704 - 702 - 1 = 1番目の数値となる
  // aaa = 0番目
  // aab = 1番目
  // となる。
  //
  // 文字列の長さ分、剰余を求めて、文字列に変換する
  //
  // 704 - 702 - 1 = 1
  // 1桁目 = 1 % 26               = 1 = a + 1 = b
  // 2桁目 = (1 / 26) % 26        = 0 = a + 0 = a
  // 3桁目 = ((1 / 26) / 26) % 26 = 0 = a + 0 = a
  ll k = N - base - 1;
  string ans = "";
  for (int i = 0; i < len; i++) {
    ll remainder = k % 26;
    ans = char('a' + remainder) + ans;

    ll quotient = k / 26;
    k = quotient;
  }

  cout << ans << endl;
  return 0;
}
