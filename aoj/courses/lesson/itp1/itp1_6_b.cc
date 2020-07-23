#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  // S = spade
  // H = heart
  // C = club
  // D = diamond
  vector<char> suits = {'S', 'H', 'C', 'D'};

  map<char, vector<int>> cards;
  for (int i = 0; i < 4; i++) {
    char suit = suits.at(i);
    cards[suit] = vector<int>(13, 0);
  }

  for (int i = 0; i < n; i++) {
    char suit;
    int num;
    cin >> suit >> num;

    num--; // 0-indexed
    cards.at(suit).at(num) = 1;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      char suit = suits.at(i);

      if (cards.at(suit).at(j) == 0) {
        // j + 1 ... 1-indexed
        cout << suit << " " << (j + 1) << endl;
      }
    }
  }
  return 0;
}
