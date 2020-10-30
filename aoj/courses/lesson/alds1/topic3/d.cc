#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  // \  /
  //  \/
  int depth = 0;
  int triangle_count = 0;

  vector<int> L;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);
    if (c == '\\') {
      // "\" の面積は (縦 * 横 * 1/2) の正三角形の半分であるが、
      // 小数を取り扱うことによる誤差の発生を防止するため、正三角形の数を数える。
      triangle_count += (depth * 2) + 1;
      depth += 1;
    } else if (c == '/') {
      depth -= 1;
      triangle_count += (depth * 2) + 1;
    }

    if (depth == 0) {
      int area = triangle_count / 2;
      L.push_back(area);
    }
    // cout << "char:           " << c << endl;
    // cout << "depth:          " << depth << endl;
    // cout << "triangle_count: " << triangle_count << endl;
  }

  int k = (int)L.size();
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += L.at(i);
  }

  cout << sum << endl;
  cout << k;
  for (int i = 0; i < k; i++) {
    cout << " ";
    cout << L.at(i);
  }
  cout << endl;
  return 0;
}
