#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a.at(i);
  }

  int left_player = 0;
  int left_rate = 0;
  int right_player = 0;
  int right_rate = 0;
  int a_size = a.size();
  for (int i = 0; i < (a_size / 2); i++) {
    if (a.at(i) > left_rate) {
      left_player = i;
      left_rate = a.at(i);
    }
  }
  for (int i = (a_size / 2); i < a_size; i++) {
    if (a.at(i) > right_rate) {
      right_player = i;
      right_rate = a.at(i);
    }
  }

  if (left_rate > right_rate) {
    cout << (right_player + 1) << endl;
  } else {
    cout << (left_player + 1) << endl;
  }
  return 0;
}
