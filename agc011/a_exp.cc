#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // N 乗客の人数
  // C バスの定員
  // K バスを待てる時間
  int N, C, K;
  cin >> N >> C >> K;

  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }

  sort(T.begin(), T.end());

  int ans = 0;
  int departure_time = 0;
  int num_of_passengers = 0;
  // O(N)
  for (int i = 0; i < N; i++) {
    // 乗客を1人ピックアップ
    int arrived_time = T.at(i);
    num_of_passengers++;
    // 一人目の乗客の場合、この乗客が最大限待てる時間が、バスの出発時間となる
    if (num_of_passengers == 1) {
      departure_time = arrived_time + K;
    }

    // 最後の乗客の場合はバスを発車する
    if (i == (N - 1)) {
      ans++;
      continue;
    }

    // バスの乗客が定員に到達した場合は、バスを発車する
    if (num_of_passengers == C) {
      num_of_passengers = 0;
      ans++;
      continue;
    }

    // 次のバスの乗客が、バスの出発時刻に間に合わない場合は、バスを発車する
    if (T.at(i + 1) > departure_time) {
      num_of_passengers = 0;
      ans++;
      continue;
    }
  }

  cout << ans << endl;
  return 0;
}
