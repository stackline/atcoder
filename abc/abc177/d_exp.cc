#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union-Find木 (経路圧縮あり、ランク無し、サイズあり)
// ref. https://www.slideshare.net/chokudai/union-find-49066733
struct UnionFind {
  vector<int> parent;
  vector<int> size;

  UnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
      // parent[i] = i ならば根
      parent.at(i) = i;
    }
  }

  // 木の根を求める
  int root(int x) {
    // 頂点 x が根の場合は根の値を返す
    if (parent.at(x) == x) {
      return x;
    // 頂点 x が根ではない場合は経路圧縮を行いつつ、根の値を返す
    } else {
      // 経路圧縮
      parent.at(x) = root(parent.at(x));
      return parent.at(x);
    }
  }

  // 頂点 x と y が同じ集合に属するか否か
  bool same(int x, int y) {
    return root(x) == root(y);
  }

  // 頂点 x が所属する集合のサイズを求める
  int size_of(int x) {
    return size.at(root(x));
  }

  // 頂点 x と y の属する集合を併合
  void unite(int x, int y) {
    // 2頂点の根を求める
    x = root(x);
    y = root(y);

    // 頂点 x と y が同じ集合に所属している場合は併合する必要がない
    if (x == y) { return; }

    // 要素数が多い方に併合する
    if (size.at(x) > size.at(y)) {
      // 以下の親子関係となる
      // (x == root of x || y == root of y のケースもある)
      //
      // [y] --> [root of y] --+
      //                       |--> [root of x]
      // [x] ------------------+
      //
      parent.at(y) = x;
      size.at(x) += size.at(y);
    } else {
      parent.at(x) = y;
      size.at(y) += size.at(x);
    }
  }
};

int main() {
  int n; // 人数
  cin >> n;
  int m; // 情報の数
  cin >> m;

  UnionFind uf(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-indexed
    uf.unite(x, y);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, uf.size_of(i));
  }
  cout << ans << endl;
  return 0;
}
