#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // A = 65
  // C = 67
  // Z = 90
  for (int i = 0; i < (int)s.size(); i++) {
    // 0-indexed な文字列Aからの距離
    int x = s.at(i) - 'A';
    // x から n 文字後の文字にする
    // A-Z は26文字で構成されており、26文字を超えた場合は1周するので、26の剰余を求める
    //
    // 仮に s.at(i) = 'A' の場合、A = 65、A = 65 のため、A - A = Aから0文字目となる。
    // 仮に s.at(i) = 'B' の場合、B = 66、A = 65 のため、B - A = Aから1文字目となる。
    // 仮に s.at(i) = 'Z' の場合、Z = 90、A = 65 のため、Z - A = Aから25文字目となる。
    // x は 0-indexed である。
    //
    // 3件目のケースについて、n = 2 の場合、25 + 2 = 27 となる。
    // つまり、Aから27文字目となる。
    // しかし、Zの次はAに戻るため、(x+n) % 26 で、A-Zの周期で割る。
    // Aから27文字目は、Aから1文字目となる。
    //
    // Aから0文字目はAのため、Aから1文字目はBとなる。
    //
    x = (x+n) % 26;
    // Aからx文字後の文字を表示する
    cout << static_cast<char>('A'+x);
  }
  cout << endl;
  return 0;
}
