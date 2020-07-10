#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100005;
int main() {
  int N;
  cin >> N;

  vector<int> v(MX, 0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    // 0 から 1 を引くケースを 0 以上の要素数で管理するために加算
    a++;

    v.at(a - 1)++;
    v.at(a)++;
    v.at(a + 1)++;
  }

  int ans = 0;
  for (int i = 0; i < MX; i++) {
    ans = max(ans, v.at(i));
  }

  cout << ans << endl;
  return 0;
}
