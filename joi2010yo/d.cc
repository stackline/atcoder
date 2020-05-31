#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; // 4 <= n <= 10
  int k; // 2 <= k <= 4
  cin >> n >> k;

  // 表現できる最大の数 = 99 * 4枚 = 99999999
  vector<bool> checker(100000000, false);

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  sort(v.begin(), v.end());
  int ans = 0;
  do {
    string a;
    for (int i = 0; i < k; i++) {
      a += to_string(v.at(i));
    }
    int b = stoi(a);

    // パターンから生成した数字の種類をカウントアップする
    // 2回目以降、同じ数字が発生した場合はスキップする
    if (checker.at(b) == false) {
      ans++;
      checker.at(b) = true;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
  return 0;
}
