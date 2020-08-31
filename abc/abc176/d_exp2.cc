#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// BFS (幅優先探索)
//
// NOTE:
// 全てコストが 0 の場合は queue や stack を使う。
// 全てコストが 1 の場合は queue を使う。
// コストが 0 と 1 の両方ある場合は deque を使う。
// --> コストが低い方を push_front、コストが高い方を push_back することで、コストが低い方から順番に幅優先探索を行う。
//
int main() {
  int h, w;
  cin >> h >> w;
  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  si--; sj--; ti--; tj--;

  // 入力受取
  vector<string> s(h);
  for (int i = 0; i < h; i++) { cin >> s.at(i); }

  // BFSのためのデータ構造
  const int INF = 1e9;
  vector<vector<int>> dist(h, vector<int>(w, INF)); // 全マスのコストを INF に初期化
  deque<pair<int, int>> que;

  // 初期条件
  dist.at(si).at(sj) = 0; // スタート地点をコスト0とする
  que.push_front(make_pair(si, sj));

  // キューから取り出した要素について、上下左右を探索する際に利用
  const vector<int> di { -1,  0, 1, 0 };
  const vector<int> dj {  0, -1, 0, 1 };

  // BFS開始（キューが空になるまで探索を行う）
  while (!que.empty()) {
#ifndef ONLINE_JUDGE
    // キューの状態を確認
    deque<pair<int, int>> dup = que;
    cout << "### deque status check" << endl;
    while (!dup.empty()) {
      pair<int, int> a1 = dup.front();
      dup.pop_front();
      cout << "(" << a1.first +1 << ", " << a1.second +1 << "), ";
    }
    cout << endl;
#endif

    // キューから先頭要素を取り出す
    int i = que.front().first;  // 縦軸
    int j = que.front().second; // 横軸
    que.pop_front();
    int d = dist.at(i).at(j);   // 今の距離 (コスト)

    // 徒歩
    for (int v = 0; v < 4; v++) {
      int next_i = i + di.at(v);
      int next_j = j + dj.at(v);
      // 移動先が表の外の場合は探索しない
      if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) { continue; }
      // 移動先が壁の場合は探索しない
      if (s.at(next_i).at(next_j) == '#') { continue; }
      // 移動先のコストが「移動元のコスト」以下である場合は、コストを更新する必要がないため探索しない
      if (dist.at(next_i).at(next_j) <= d) { continue; }

      // 上下左右について、徒歩で移動できる場合は移動元と同じコストをセットする
      dist.at(next_i).at(next_j) = d;
      // 徒歩で移動可能なマスをキューの先頭に追加し、優先的に探索する
      que.push_front(make_pair(next_i, next_j));
    }

    // ワープ
    for (int ei = -2; ei <= 2; ei++) {
      for (int ej = -2; ej <= 2; ej++) {
        int next_i = i + ei;
        int next_j = j + ej;

        // 移動先がマスの外の場合はスキップ
        if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) { continue; }
        // 移動先が壁の場合はスキップ
        if (s.at(next_i).at(next_j) == '#') { continue; }
        // 移動先のコストが「移動元+1」以下である場合は、ワープ1回で辿り着けるため、ワープを行う前提ではこれ以上の低コストはないため、探索しない
        // 移動先のコストが「移動元+2」以上である場合は、ワープ1回で辿り着ける方が低コストであるため、コストを「移動元+1」で更新する
        if (dist.at(next_i).at(next_j) <= d+1) { continue; }

        dist.at(next_i).at(next_j) = d+1;
        // ワープで移動可能なマスをキューの後尾に追加し、徒歩の探索が完了した後にワープの探索を行う
        que.push_back(make_pair(next_i, next_j));
      }
    }
  }

  // ゴールのコストを確認する
  int ans = dist.at(ti).at(tj);
  // コストが INF の場合は、ワープを使っても到達できなかったため -1 とする
  if (ans == INF) { ans = -1; }
  cout << ans << endl;
  return 0;
}
