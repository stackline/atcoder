#include <bits/stdc++.h>
using namespace std;

int main() {
  // 問題の種類と目標スコア
  int D, G;
  cin >> D >> G;

  // 問題数とコンプリートボーナス
  vector<int> p(D);
  vector<int> c(D);

  int ans = 0;
  for (int i = 0; i < D; i++) {
    cin >> p.at(i) >> c.at(i);
    // 全種類の全問を解答した場合を、解答数の上限とする
    ans += p.at(i);
  }

  // どの問題を全問解答するか、bit全検索で全パターンを検証する
  for (int tmp = 0; tmp < (1 << D); tmp++) {
    bitset<10> bs(tmp);
    int total_score = 0;
    int total_answers = 0;

    // 1が立っている問題について、スコアを加算する
    for (int i = 0; i < D; i++) {
      if (bs.test(i)) {
        int score = (i + 1) * 100;
        total_score += (score * p.at(i)) + c.at(i);
        total_answers += p.at(i);
      }
    }

    // 目標スコアを超えている場合、最小の問題数の実績を更新
    if (total_score >= G) {
      ans = min(ans, total_answers);

    // 目標スコアを超えていない場合、
    // 未着手の問題の内、1問あたりの配点が最も高い問題を
    // 一定件数解くことで、目標スコアを超えれるか確認する
    } else {
      // ターゲットの問題番号を算出
      int target = -1;
      for (int i = 0; i < D; i++) {
        if (bs.test(i) == 0) {
          target = i;
        }
      }

      // 目標スコアを満たしておらず、残っている解答が無い場合はスキップ
      if (target == -1) continue;

      // 目標スコアを超えた時点で探索終了
      int score = (target + 1) * 100;
      for (int j = 1; j <= p.at(target); j++) {
        int expected_score = total_score + (score * j);
        if (expected_score >= G) {
          total_answers += j;
          ans = min(ans, total_answers);
          break;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
