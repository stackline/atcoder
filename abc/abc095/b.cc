#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int rest_gram = X;
  int donuts_count = 0;
  int minimum_donuts_gram = 1000;
  for (int i = 0; i < N; i++) {
    int donuts_gram;
    cin >> donuts_gram;

    // ドーナツを1つ作る
    rest_gram -= donuts_gram;
    donuts_count++;
    // 最小コストで作れるドーナツを判定する
    minimum_donuts_gram = min(minimum_donuts_gram, donuts_gram);
  }

  // 余った材料で作成できるドーナツの数
  int c = rest_gram / minimum_donuts_gram;

  cout << (donuts_count + c) << endl;
  return 0;
}
