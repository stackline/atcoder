#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N; // 1 <= N <= 100

  // 市名、点数、都市番号
  vector<tuple<string, int, int>> v;
  for (int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    v.push_back(make_tuple(s, (p * -1), i));
  }
  // 市名の昇順、点数の降順でソート
  // 点数は予め -1 で逆転させているので、昇順のソートが降順になる
  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    int restaurant_num = get<2>(v.at(i)) + 1; // 1-indexed
    cout << restaurant_num << endl;
  }
  return 0;
}
