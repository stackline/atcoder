#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 3
// 1 2 3
int main() {
  int N;
  cin >> N;

  // 奇数 + 奇数 => 偶数
  // 偶数 + 偶数 => 偶数
  int odd_count = 0;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    if (n % 2 == 1) {
      odd_count++;
    }
  }

  // 「奇数」が偶数個あれば、消し込むことが可能
  // 「奇数」が奇数個あれば、1つ消し込めない
  if (odd_count % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
