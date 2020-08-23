#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 O(n * 4 * 1000)
int main() {
  int n;
  string s;
  cin >> n >> s;

  // 1. DP配列全体を「DPの種類に応じた初期値」で初期化
  // 2. 初期条件を入力
  // dp[pos(sition)][len(gth)][current] = bool
  vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(4, vector<bool>(1000, false)));

  dp.at(0).at(0).at(0) = true;

  // 3. ループを回す
  // i=position
  for (int i = 0; i < n; i++) {
    // j=length
    for (int j = 0; j < 4; j++) {
      // k=current
      for (int k = 0; k < 1000; k++) {
        if (dp.at(i).at(j).at(k) == false) { continue; }

        // 例 n=4, s=0224
        //
        // 0 0 0
        //   1 0 0   = true
        //   1 1 "0" = true
        // 0 0 1 〜 0 0 999
        // 0 1 0 〜 0 1 999
        // 0 2 0 〜 0 2 999
        // 0 3 0 〜 0 3 999
        //   この状態にできないため false であり、continue
        // 1 0 0
        //   2 0 0     = true // 次の文字を残さない
        //   2 1 "2"   = true // 次の文字を残す
        // 1 1 "0"
        //   2 1 "0"   = true
        //   2 2 "02"  = true
        // 2 0 0
        //   3 0 0     = true
        //   3 1 "2"   = true
        // 2 1 "2"
        //   3 1 "2"   = true
        //   3 2 "22"  = true
        // 2 1 "0"
        //   3 1 "0"   = true
        //   3 2 "02"  = true
        // 2 2 "02"
        //   3 2 "02"  = true
        //   3 3 "022" = true
        // 3 0 0
        //   4 0 0     = true
        //   4 1 "4"   = true
        // 3 1 "2"
        //   4 1 "2"   = true
        //   4 2 "23"  = true
        // 3 1 "0"
        //   4 1 "0"   = true
        //   4 2 "04"  = true
        // 3 2 "22"
        //   4 2 "22"  = true
        //   4 3 "224" = true
        // 3 2 "02"
        //   4 2 "02"  = true
        //   4 3 "024" = true
        // 3 3 "022"
        //   4 3 "022" = true
        //   (j = 3 のため、この処理は行われない) 4 4 xxx

        // ### 文字を残さない場合
        // 文字を残さないため、length と current は変わらない。
        // position だけ1進める。
        //
        // 例えば、db[0][0][0] から dp[1][0][0] に遷移した場合、
        // length も current も上限をあふれないため、この状態にできるため
        // dp[1][0][0] = true に更新する。
        dp.at(i+1).at(j).at(k) = true;

        // ### 文字を残す場合
        // j = 3 の状態で文字を残すと4桁になるため、j <= 2 とする
        if (j <= 2) {
          // pos: ポジションを1つ前に進める。
          // len: そのポジションの数字を残すため、len をインクリメントする。
          // current: 遷移元で残していた数字が 22 の場合、22 * 10 = 220 で桁をあげる。文字列 s から残す数字を取得し、1桁目にセットする。
          dp.at(i+1).at(j+1).at(k*10 + (s.at(i)-'0')) = true;
        }
      }
    }
  }

  // 4. テーブルから解を得て出力
  int ans = 0;
  for (int k = 0; k < 1000; k++) {
    if (dp.at(n).at(3).at(k) == true) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
