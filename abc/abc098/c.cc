#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  // 東に向いている人の累積和
  // 西に向いている人の累積和
  vector<int> cs_east(N + 1, 0);
  vector<int> cs_west(N + 1, 0);
  for (int i = 0; i < N; i++) {
    int is_east = (S.at(i) == 'E');
    int is_west = (S.at(i) == 'W');
    cs_east.at(i + 1) = cs_east.at(i) + is_east;
    cs_west.at(i + 1) = cs_west.at(i) + is_west;
  }

  int ans = N;
  for (int i = 0; i < N; i++) {
    int from_west_to_east = cs_west.at(i);
    int from_east_to_west = cs_east.at(N) - cs_east.at(i + 1);
    int num = from_west_to_east + from_east_to_west;
    ans = min(ans, num);
  }

  cout << ans << endl;
  return 0;
}
