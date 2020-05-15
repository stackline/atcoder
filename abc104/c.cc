#include <bits/stdc++.h>
using namespace std;

int d, g;
vector<int> p;
vector<int> c;

int rec(int i, int sum, int count, string bits) {
  // ベースケース
  if (sum >= g) {
    return count;
  }
  if (i == d) {
    int pos = bits.find_last_of('0');
    int score = (pos + 1) * 100;
    for (int j = 0; j < (int) p.at(pos); j++) {
      sum += score;
      count++;
      if (sum >= g) {
        break;
      }
    }
    if (sum >= g) {
      return count;
    } else {
      return 0;
    }
  }

  // 完全に解く場合
  int p1 = rec(i + 1,
               sum + ((i + 1) * 100 * p.at(i)) + c.at(i),
               count + p.at(i),
               bits + '1');
  // 全く解かない場合
  int p2 = rec(i + 1, sum, count, bits + '0');

  if (p1 == 0) {
    return p2;
  }
  if (p2 == 0) {
    return p1;
  }
  return min(p1, p2);
}

int main() {
  cin >> d >> g;
  p.resize(d);
  c.resize(d);
  for (int i = 0; i < d; i++) {
    cin >> p.at(i) >> c.at(i);
  }

  string bits = "";
  int ans = rec(0, 0, 0, bits);

  cout << ans << endl;
  return 0;
}
