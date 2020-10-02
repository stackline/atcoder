#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  string s;
  cin >> s;

  int len = s.length();

  // ### char 型と文字列リテラルを比較するとエラー
  //
  //   s.at(len-1) == "s"
  //
  // ### エラー
  //
  //   ISO C++ forbids comparison between pointer and integer [-fpermissive]
  //
  // "s" は文字列リテラルで char 型の配列
  // s.at(len-1) は char 型
  // 比較の際 char 型の配列を pointer として取り扱い、char 型を int として取り扱い、型不一致でエラー
  //
  if (s.at(len-1) == 's') {
    s += "es";
  } else {
    s += "s";
  }

  cout << s << endl;
  return 0;
}
