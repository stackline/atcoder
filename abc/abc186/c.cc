#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  //    10進法 8進法
  // 7  7      7
  // 15        17
  // 17 17

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    // iを8進数の文字列で表現した場合
    char buffer[50];
    sprintf(buffer, "%o", i);
    string i_octal = buffer;

    // iを10進数の文字列で表現した場合
    string i_decimal = to_string(i);

    if (i_octal.find("7") == string::npos &&
        i_decimal.find("7") == string::npos) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
