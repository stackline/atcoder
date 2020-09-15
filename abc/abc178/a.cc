#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr); // cin 時に cout を flush しない
  // cout << "hogehoge" << '\n';  // endl は改行後に flush するので、改行のみとする
  // ios::sync_with_stdio(false); // cin/cout と scanf/printf が混在する場合は注意
}

int main() {
  init();
  int a;
  cin >> a;
  if (a == 0) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
