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
  // cin >> n;
  n = 5;

  int m; // 情報の数
  // cin >> m;
  m = 3;

  vector<pair<int, int>> a(m); // 情報
  // for (int i = 0; i < m; i++) {
  //   int x, y;
  //   cin >> x >> y;
  //   x--; y--;
  //   a.at(i) = make_pair(x, y);
  // }
  a.at(0) = make_pair(0, 1);
  a.at(1) = make_pair(2, 3);
  a.at(2) = make_pair(4, 0);

  UnionFind uf(n);
  for (int i = 0; i < (int)a.size(); i++) {
    pair<int, int> p = a.at(i);
    uf.unite(p.first, p.second);
  }

  cout << "whether 0 and 2 belong to same set?: ";
  cout << (uf.same(0, 2) ? "Yes" : "No") << endl;

  cout << "whether 1 and 4 belong to same set?: ";
  cout << (uf.same(1, 4) ? "Yes" : "No") << endl;

  cout << "what is root of 0?: ";
  cout << uf.root(0) << endl;

  cout << "what is root of 1?: ";
  cout << uf.root(1) << endl;

  cout << "what is root of 2?: ";
  cout << uf.root(2) << endl;

  cout << "what is root of 3?: ";
  cout << uf.root(3) << endl;

  cout << "what is root of 4?: ";
  cout << uf.root(4) << endl;

  cout << "what size is the set 0 belongs to?: ";
  cout << uf.size_of(0) << endl;

  cout << "what size is the set 1 belongs to?: ";
  cout << uf.size_of(1) << endl;

  cout << "what size is the set 2 belongs to?: ";
  cout << uf.size_of(2) << endl;

  cout << "what size is the set 3 belongs to?: ";
  cout << uf.size_of(3) << endl;

  cout << "what size is the set 4 belongs to?: ";
  cout << uf.size_of(4) << endl;
  return 0;
}
