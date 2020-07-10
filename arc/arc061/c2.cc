#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int str_len = (int)S.size();
  int bit_len = str_len - 1;
  long long ans = 0;

  // Bit全検索で全パターンを加算する
  for (int tmp = 0; tmp < (1 << bit_len); tmp++) {
    bitset<10> bs(tmp);

    // ビット列の特定の桁に 1 が立っている場合、+ 記号の挿入とみなす
    string num_string;
    for (int i = 0; i < str_len; i++) {
      num_string += S.at(i);

      // それまでに登場した左の文字列を数字とみなして、加算する
      // num_string は初期化する
      if (i < bit_len && bs.test(i)) {
        ans += stoll(num_string);
        num_string = "";
      }
    }
    // + 記号が最後に登場した後の数字文字列を加算する
    ans += stoll(num_string);
  }

  cout << ans << endl;
  return 0;
}
