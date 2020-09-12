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

  int n, q;
  cin >> n >> q;

  queue<pair<string, int>> que;
  for (int i = 0; i < n; i++) {
    string name;
    int time;
    cin >> name >> time;
    que.push(make_pair(name, time));
  }

  int total = 0;
  while (que.size() > 0) {
    pair<string, int> p = que.front();
    que.pop();

    if (p.second > q) {
      p.second -= q;
      total += q;
      que.push(p);
    } else {
      total += p.second;
      cout << p.first << " " << total << '\n';
    }
  }
  return 0;
}
