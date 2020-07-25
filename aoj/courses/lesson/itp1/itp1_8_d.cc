#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  char s[100], p[100];
  cin >> s >> p;

  char s2[200];
  strcat(s2, s);
  strcat(s2, s);

  if (strstr(s2, p) == NULL) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
