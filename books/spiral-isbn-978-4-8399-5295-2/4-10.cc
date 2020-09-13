#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr); // cin 時に cout を flush しない
  // cout << "hogehoge" << '\n';  // endl は改行後に flush するので、改行のみとする
  // ios::sync_with_stdio(false); // cin/cout と scanf/printf が混在する場合は注意
}

void print(vector<double> v) {
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v.at(i) << " ";
  }
  cout << '\n';
}

int main() {
  init();

  vector<double> v;
  v.push_back(0.1); // { 0.1 }
  v.push_back(0.2); // { 0.1, 0.2 }
  v.push_back(0.3); // { 0.1, 0.2, 0.3 }
  v.at(2) = 0.4;    // { 0.1, 0.2, 0.4 }
  print(v);

  v.insert(v.begin() + 2, 0.8); // { 0.1, 0.2, 0.8, 0.4 }
  print(v);

  v.erase(v.begin() + 1); // { 0.1, 0.8, 0.4 }
  print(v);

  v.push_back(0.9); // { 0.1, 0.8, 0.4, 0.9 }
  print(v);

  return 0;
}
