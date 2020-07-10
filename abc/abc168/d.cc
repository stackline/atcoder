#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  // vector<int> dist(n, -1);
  vector<int> guide_post(n, -1);
  queue<int> que;

  guide_post[0] = 0;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    // graph[1][0] = 0
    // graph[1][1] = 2
    // graph[1][2] = 3
    //
    // graph[1]
    //   0 は -1 ではないのでスキップ
    //   2 は -1 のため、処理を行う
    //
    for (int nv : graph[v]) {
      if (guide_post[nv] != -1) {
        continue;
      }
      // guide_post[2] = 1;
      guide_post[nv] = v;
      que.push(nv);
    }
  }

  bool flag = true;
  for (int v = 1; v < n; v++) {
    if (guide_post[v] == -1) {
      flag = false;
    }
  }
  if (flag == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  for (int v = 1; v < n; v++) {
    cout << (guide_post[v] + 1) << endl;
  }

  return 0;
}
