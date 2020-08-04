#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  char ch;
  int alpha_size = 'z' - 'a' + 1;
  vector<int> counter(alpha_size, 0);
  while (1) {
    cin >> ch;

    // NOTE: EOF は control + d で送信
    if (cin.eof()) { break; } // 終端の場合、終了する
    if (!isalpha(ch)) { continue; } // アルファベット以外は集計しない
    if (isupper(ch)) { ch = tolower(ch); } // 大文字は小文字に変換

    int alpha_num = ch - 'a';
    counter.at(alpha_num)++;
  }

  for (int i = 0; i < alpha_size; i++) {
    char c = 'a' + i;
    cout << c << " : " << counter.at(i) << endl;
  }
  return 0;
}
