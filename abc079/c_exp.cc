#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> a(4);
  for (int i = 0; i < (int)s.size(); i++) {
    a[i] = s[i] - '0';
  }

  for (int x = 0; x < 8; x++) {
    int sum = a[0];
    string s;
    s += (char)('0' + a[0]);

    for (int i = 0; i < 3; i++) {
      // ### ビット演算
      // *  & : 論理積
      // * << : 左シフト
      //
      // 0000
      //   0000 & 0001 == 0000 == 0
      //   0000 & 0010 == 0000 == 0
      //   0000 & 0100 == 0000 == 0
      // 0001
      //   0001 & 0001 == 0001 == 1
      //   0001 & 0010 == 0000 == 0
      //   0001 & 0100 == 0000 == 0
      // 0002
      //   0010 & 0001 == 0000 == 0
      //   0010 & 0010 == 0010 == 2
      //   0010 & 0100 == 0000 == 0
      // 0003
      //   0011 & 0001 == 0001 == 1
      //   0011 & 0010 == 0010 == 2
      //   0011 & 0100 == 0000 == 0
      // 0004
      //   0100 & 0001 == 0000 == 0
      //   0100 & 0010 == 0000 == 0
      //   0100 & 0100 == 0100 == 4
      // 0005
      //   0101 & 0001 == 0001 == 1
      //   0101 & 0010 == 0000 == 0
      //   0101 & 0100 == 0100 == 4
      // 0006
      //   0110 & 0001 == 0000 == 0
      //   0110 & 0010 == 0010 == 2
      //   0110 & 0100 == 0100 == 4
      // 0007
      //   0111 & 0001 == 0001 == 1
      //   0111 & 0010 == 0010 == 2
      //   0111 & 0100 == 0100 == 4
      //
      if (x & (1 << i)) {
        sum += a[i + 1];
        s += '+';
        s += (char)('0' + a[i + 1]);
      } else {
        sum -= a[i + 1];
        s += '-';
        s += (char)('0' + a[i + 1]);
      }
    }

    if (sum == 7) {
      s += "=7";
      cout << s << endl;
      return 0;
    }
  }

  return 0;
}