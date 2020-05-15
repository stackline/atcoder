#include <bits/stdc++.h>
using namespace std;

int calc(int &g, int min_count, vector<int> p, vector<int> c, int sum, int count, int i) {
  // 問題を解いた時の配点
  sum += (i + 1) * 100;
  p[i]--;
  count++;
  // コンプリートボーナス
  if (p[i] == 0) {
    sum += c[i];
  }

  // ベースケース
  // 目標点数を超えたら探索終了
  // 別ノードを探索する際、現在のミニマムまでしか探索しない
  if (sum >= g || count == min_count) {
    return count;
  }

  // 再帰ステップ
  // O(n) / 線形時間
  // 1 <= pi <= 100
  for (int j = 0; j < (int) p.size(); j++) {
    if (p[j] > 0) {
      int calculated = calc(g, min_count, p, c, sum, count, j);
      min_count = min(min_count, calculated);
    }
  }

  return min_count;
}

int main() {
  int d, g;
  cin >> d >> g;
  vector<int> p(d);
  vector<int> c(d);
  // O(n) / 線形時間
  // 1 <= d <= 10
  for (int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
  }

  int min_count = 0;
  // O(n) / 線形時間
  // 1 <= d <= 10
  for (int i = 0; i < d; i++) {
    min_count += p[i];
  }

  // O(n log n log n-1...) / 線形時間
  // 1 <= d <= 10
  for (int i = 0; i < d; i++) {
    int calculated = calc(g, min_count, p, c, 0, 0, i);
    min_count = min(min_count, calculated);
  }

  cout << min_count << endl;
  return 0;
}
