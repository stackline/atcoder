#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  ll money = 1000;
  ll stock = 0;
  for (int i = 0; i < N; i++) {
    // i日目の株価
    ll i_day_stock_price = A.at(i);

    // 最終日より前の日
    if (i < N - 1) {
      ll i_next_day_stock_price = A.at(i + 1);

      // 翌日、株価が上昇する場合は買う
      if (i_next_day_stock_price > i_day_stock_price) {
        ll add_stock = money / i_day_stock_price;
        ll reduce_money = add_stock * i_day_stock_price;
        stock = stock + add_stock;
        money = money - reduce_money;
      // 翌日、株価が下落する場合は売る
      // （下落してから買い直す）
      } else if (i_next_day_stock_price < i_day_stock_price) {
        money = money + (i_day_stock_price * stock);
        stock = 0;
      }
    }

    // 最終日は売る
    if (i == N - 1) {
      money = money + (i_day_stock_price * stock);
      stock = 0;
    }
  }

  cout << money << endl;
  return 0;
}
