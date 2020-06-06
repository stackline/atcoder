#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int ans = 0;

  for (int i = 1; i <= N; i++) {
    string s = to_string(i);
    int len = s.length();

    int num = 0;
    for (int j = 0; j < len; j++) {
      char c = s.at(j);
      num += c - '0';
    }

    if (num >= A && num <= B) {
      ans += i;
    }
  }

  cout << ans << endl;
  return 0;
}
