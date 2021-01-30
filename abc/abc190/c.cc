#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int judge(vector<int> &a, vector<int> &b, vector<int> dish) {
  int cnt = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    int ai = a.at(i);
    int bi = b.at(i);
    if (dish.at(ai) > 0 && dish.at(bi) > 0) {
      cnt++;
    }
  }
  return cnt;
}

int search(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d,
           vector<int> dish, int k) {
  // ベースケース
  if (k >= (int)c.size()) {
    // cout << "debug" << endl;
    // for (int i = 0; i < (int)dish.size(); i++) {
    //   cout << dish.at(i) << " ";
    // }
    // cout << endl;
    // 判定する
    return judge(a, b, dish);
  }

  // 再帰ステップ
  // cを選ぶ場合
  vector<int> dish_c = dish;
  dish_c.at(c.at(k))++;
  int c_cnt = search(a, b, c, d, dish_c, k + 1);

  // dを選ぶ場合
  vector<int> dish_d = dish;
  dish_d.at(d.at(k))++;
  int d_cnt = search(a, b, c, d, dish_d, k + 1);

  return max(c_cnt, d_cnt);
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i) >> b.at(i);
  }

  int k;
  cin >> k;
  vector<int> c(k);
  vector<int> d(k);
  for (int i = 0; i < k; i++) {
    cin >> c.at(i) >> d.at(i);
  }

  // 2**16 = 65536 * 100 = 6,553,600
  vector<int> dish(n + 1);
  int ans = search(a, b, c, d, dish, 0);
  cout << ans << endl;
  return 0;
}
