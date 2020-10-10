#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;

  vector<int> v(200001, 0);
  int cursor = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    v.at(p)++;

    for (int j = cursor; j <= 200000; j++) {
      if (v.at(j) == 0) {
        cout << j << endl;
        cursor = j;
        break;
      }
    }
  }

  return 0;
}
