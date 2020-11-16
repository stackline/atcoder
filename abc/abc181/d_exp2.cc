#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(string s) {
  // 1桁
  if (s.size() == 1) {
    if (stoi(s) % 8 == 0) {
      return true;
    }
    return false;
  }
  // 2桁
  if (s.size() == 2) {
    if (stoi(s) % 8 == 0) {
      return true;
    }
    swap(s.at(0), s.at(1));
    if (stoi(s) % 8 == 0) {
      return true;
    }
    return false;
  }
  // 3桁以上
  // 各数字の登場回数を数える
  vector<int> cnt(10);
  for (auto c : s) {
    cnt.at(c - '0')++;
  }
  // 100〜999 の内の 8 の倍数について、作成可能かどうか検討する。
  // 000〜099 は 0 を 1 つ以上含むため、1 〜 9 で構成する数字列 s では作れない。
  // 同様に 160 や 800 など、100 以上の数で 8 の倍数で 0 を含むものも、数字列 s からは作れない。
  for (int i = 0; i < 1000; i = i + 8) {
    //
    // ### 例: x = 123 の場合
    // 123 % 10 = 3 から 3 をインクリメントする。
    // 123 / 10 = 12 で桁を1つ下げる。
    // 12 % 10 = 2 から 2 をインクリメントする。
    // 12 / 10 = 1 で桁を1つ下げる。
    // 1 % 10 = 1 から 1 をインクリメントする。
    //
    // 1,2,3 がそれぞれ 1 回ずつ登場したことが記録される。
    //
    // ### 例 : x = 8 の場合
    // 8 % 10 = 8 から 8 をインクリメントする。
    // 8 / 10 = 0 から x = 0 とする。
    // 0 % 10 = 0 から 0 をインクリメントする。
    // 0 / 10 = 0 から x = 0 とする。
    // 0 % 10 = 0 から 0 をインクリメントする。
    //
    // 0 が 2 回、8 が 1 回登場したことが記録される。
    //
    int x = i;
    vector<int> nc(10);
    for (int j = 0; j < 3; j++) {
      nc.at(x % 10)++;
      x = x / 10;
    }

    bool can = true;
    for (int j = 0; j < 10; j++) {
      if (nc.at(j) > cnt.at(j)) {
        can = false;
      }
    }
    if (can) {
      return true;
    }
  }

  return false;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;
  cout << (solve(s) ? "Yes" : "No") << endl;
  return 0;
}
