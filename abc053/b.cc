#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int begin = s.find_first_of('A');
  int end = s.find_last_of('Z');
  int ans = end - begin + 1;

  cout << ans << endl;
  return 0;
}
