#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(N + N + N^4 + Q)
// Q の最大値は N^2
// そのため、計算量は O(N^4)
// N <= 50 のため、50^4 = 6_250_000 ぐらい
int main() {
  // たこ焼き機の縦・横の長さ
  int N;
  cin >> N;

  // たこ焼きのおいしさ
  vector<vector<int>> D(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> D.at(i).at(j);
    }
  }

  // たこ焼きのおいしさの累積和
  vector<vector<int>> s(N + 1, vector<int>(N + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      s.at(i + 1).at(j + 1) = s.at(i).at(j + 1)
                            + s.at(i + 1).at(j)
                            - s.at(i).at(j)
                            + D.at(i).at(j);
    }
  }

  vector<int> takoyaki((N * N) + 1, 0);
  for (int x1 = 0; x1 <= N; x1++) {
    for (int x2 = x1 + 1; x2 <= N; x2++) {
      for (int y1 = 0; y1 <= N; y1++) {
        for (int y2 = y1 + 1; y2 <= N; y2++) {
          int num_of_takoyaki = (x2 - x1) * (y2 - y1);
          int oishisa_sum = s.at(x2).at(y2) - s.at(x1).at(y2) - s.at(x2).at(y1) + s.at(x1).at(y1);
#ifndef ONLINE_JUDGE
          cout << "x1: " << x1 << ", x2: " << x2 << ", y1: " << y1 << ", y2: " << y2 << endl;
          cout << "num_of_takoyaki: " << num_of_takoyaki << endl;
          cout << "oishisa_sum: " << oishisa_sum << endl;
#endif
          takoyaki.at(num_of_takoyaki) = max(takoyaki.at(num_of_takoyaki), oishisa_sum);
        }
      }
    }
  }

#ifndef ONLINE_JUDGE
  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < N + 1; j++) {
      cout << s.at(i).at(j) << " ";
    }
    cout << endl;
  }
#endif
#ifndef ONLINE_JUDGE
  for (int i = 0; i < (N * N + 1); i++) {
    cout << i << " : " << takoyaki.at(i) << endl;
  }
#endif

  // 店員の数
  int Q;
  cin >> Q;

  // 店員ごとの、一度に焼けるたこ焼きの上限
  for (int i = 0; i < Q; i++) {
    int num;
    cin >> num;
    int ans = 0;
    // 例えば4個のたこ焼きを焼ける店員がいる
    // 必ずしも4個焼く必要はない
    // 縦3列、横3列など、3個焼くことで、おいしさの総量が4個の時より大きい場合がある
    //
    // 例えば店員は4個たこ焼きを焼けるが、たこ焼き機が N = 3 の場合
    //
    // NOTE: 二次元累積和を作成した後、予め
    // 要素数 i のおいしさの総和が、要素数 j のおいしさの総和より大きい場合、
    // 要素数 j のおいしさの総和を、i のおいしさの総和で更新することで、
    // 以下の for ループを短縮することができるはず。
    // ただし、i < j とする。
    for (int i = 0; i <= num; i++) {
      ans = max(ans, takoyaki.at(i));
    }
    cout << ans << endl;
  }

  return 0;
}
