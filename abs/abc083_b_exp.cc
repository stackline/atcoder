#include <bits/stdc++.h>
using namespace std;

int calc(int num) {
  int result = 0;
  while (num != 0) {
    // 一桁目の数値を加算する
    result = result + (num % 10);
    // 桁を一つ下げる
    num = num / 10;
  }
  return result;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int num = calc(i);
    if (num >= A && num <= B) {
      ans += i;
    }
  }

  cout << ans << endl;
  return 0;
}
