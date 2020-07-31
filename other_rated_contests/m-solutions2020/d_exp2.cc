#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }

  // x日目に、株の売却が終了した時点の所持金の最大値
  vector<ll> dp(N + 1, 0);
  // 1日目の所持金の最大値
  dp.at(1) = 1000;
  for (int i = 2; i <= N; i++) {
    // 最初に、株の売買をしないパターンをセット
    dp.at(i) = dp.at(i - 1);

    // * j日目 (1日目, 2日目, ... , i-1日) に現金で最大限に株を購入し、
    //   それをi日目に売った際の所持金をシミュレーションする
    //
    // * 何もしない場合 (前日と同じ金額を保持する場合) と比較して、
    //   手持ちの金額が最大化するケースをi日目の所持金 dp.at(i) とする
    //
    // * i = N となる最終日は、j = 1 〜 N-1 日目のそれぞれについて、
    //   以下のケースを計算し、所持金が最大化するケースを採用する
    //   * j日に取りうる最大の所持金を保持している状態
    //   * j日に最大限に株を購入し、i = N日に売却する
    //
    for (int j = 1; j <= i - 1; j++) {
      ll V = dp.at(j) / A.at(j);
      ll W = dp.at(j) + (A.at(i) - A.at(j)) * V;

      dp.at(i) = max(dp.at(i), W);
    }
  }

  cout << dp.at(N) << endl;
  return 0;
}
