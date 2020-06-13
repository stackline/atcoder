#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; // 乗客
  int C; // バスの定員
  int K; // 飛行機の到着時刻からKの時間が経過するまでにバスに乗る必要がある
  cin >> N >> C >> K;

  vector<int> T_BEGIN(N);
  vector<int> T_END(N);
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    T_BEGIN.at(i) = n;
    T_END.at(i) = n + K;
  }

  sort(T_BEGIN.begin(), T_BEGIN.end());
  sort(T_END.begin(), T_END.end());

  int ans = 0;
  for (int i = 0; i < N;) {
    // バスに1名乗せる
    int current = i;
    i++;

    // バスに座席が余っている場合、
    // 一人目の搭乗者が待機可能な時間で相乗り可能な乗客を乗せる
    for (int j = 1; j <= (C - 1); j++) {
      // index を超える場合は終了
      if ((current + j) >= N) {
        break;
      }

      if (T_BEGIN.at(current + j) <= T_END.at(current)) {
        i++;
      }
    }
    ans++;
  }

  cout << ans << endl;
  return 0;
}
