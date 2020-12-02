#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }

  sort(s.begin(), s.end());
  // unique 実施後の末尾の要素の次を指すイテレータを受け取る
  auto itr = unique(s.begin(), s.end());
  // 「unique 実施後の末尾要素の次を指すイテレータ」と
  // 「unique 実施前の末尾要素の次を指すイテレータ」を
  // 指定し、不要な要素をコンテナから削除する。
  s.erase(itr, s.end());

  int q;
  cin >> q;
  vector<int> t(q);
  for (int i = 0; i < q; i++) {
    cin >> t.at(i);
  }

  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int qx = t.at(i);
    for (int j = 0; j < (int)s.size(); j++) {
      if (s.at(j) == qx) {
        cnt++;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
