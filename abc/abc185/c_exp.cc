#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### 全探索
// * 計算量は O(L**12)
// * L = 4〜5 が上限
//   * 4**12 < 10**8 < 5**12
// * 一方で L の制約は 12 <= L <= 200 のため TLE する。
ll exhaustiveSearch(ll L) {
  ll cnt = 0;
  // clang-format off
  for (int a = 1; a <= L; a++) {                                                                     // a=1
    for (int b = 1; b <= (L - a); b++) {                                                             // b=2
      for (int c = 1; c <= (L - a - b); c++) {                                                       // c=3
        for (int d = 1; d <= (L - a - b - c); d++) {                                                 // d=4
          for (int e = 1; e <= (L - a - b - c - d); e++) {                                           // e=5
            for (int f = 1; f <= (L - a - b - c - d - e); f++) {                                     // f=6
              for (int g = 1; g <= (L - a - b - c - d - e - f); g++) {                               // g=7
                for (int h = 1; h <= (L - a - b - c - d - e - f - g); h++) {                         // h=8
                  for (int i = 1; i <= (L - a - b - c - d - e - f - g - h); i++) {                   // i=9
                    for (int j = 1; j <= (L - a - b - c - d - e - f - g - h - i); j++) {             // j=10
                      for (int k = 1; k <= (L - a - b - c - d - e - f - g - h - i - j); k++) {       // k=11
                        for (int l = 1; l <= (L - a - b - c - d - e - f - g - h - i - j - k); l++) { // l=12
                          if (a + b + c + d + e + f + g + h + i + j + k + l == L) {
                            cnt++;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  // clang-format on
  return cnt;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll L;
  cin >> L;

  // 全探索
  cout << exhaustiveSearch(L) << endl;
  return 0;
}
