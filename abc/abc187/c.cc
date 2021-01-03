#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }

  // !を後ろにつける
  vector<string> a;
  for (int i = 0; i < n; i++) {
    string b = s.at(i);
    if (b.at(0) == '!') {
      a.push_back(b.substr(1) + "!");
    } else {
      a.push_back(b);
    }
  }

  // ソートする
  sort(a.begin(), a.end());
  // 重複を削除する
  // auto itr = unique(a.begin(), a.end());
  // a.erase(itr, a.end());

  string ans = "";
  for (int i = 1; i < (int)a.size(); i++) {
    string x = a.at(i - 1);
    string y = a.at(i);
    if (x + "!" == y) {
      ans = x;
    }
  }

  if (ans != "") {
    cout << ans << endl;
  } else {
    cout << "satisfiable" << endl;
  }
  return 0;
}
