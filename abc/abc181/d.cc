#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  // 数字を昇順にソート
  sort(s.begin(), s.end());
  // 1つの数字につき3回までとして、4回目以降を除外する
  string s2;
  vector<int> cnt(10, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);
    int num = c - '0';
    if (cnt.at(num) < 3) {
      s2 += c;
      cnt.at(num)++;
    }
  }

  bool can = false;
  // string が1文字の場合
  if (s2.size() == 1 && s2 == "8") {
    can = true;
  }
  // string が2文字の場合
  if (s2.size() == 2) {
    string sa = to_string(s2.at(0) - '0') + to_string(s2.at(1) - '0');
    int a = stoi(sa);
    string sb = to_string(s2.at(1) - '0') + to_string(s2.at(0) - '0');
    int b = stoi(sb);
    if (a % 8 == 0 || b % 8 == 0) {
      can = true;
    }
  }
  // string が3文字以上の場合
  int s2_size = s2.size();
  for (int i = 0; i < s2_size; i++) {
    for (int j = i + 1; j < s2_size; j++) {
      for (int k = j + 1; k < s2_size; k++) {
        vector<int> v = {s2.at(i) - '0', s2.at(j) - '0', s2.at(k) - '0'};

        do {
          int num = v.at(0) * 100 + v.at(1) * 10 + v.at(2);
          if (num % 8 == 0) {
            can = true;
          }
        } while (next_permutation(v.begin(), v.end()));
      }
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
