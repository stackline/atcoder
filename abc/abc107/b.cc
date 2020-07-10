#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> t1(h);
  for (int i = 0; i < h; i++) {
    cin >> t1.at(i);
  }

  vector<string> t2;
  for (int i = 0; i < h; i++) {
    string row = t1.at(i);
    if (row.find("#") != string::npos) {
      t2.push_back(row);
    }
  }

  for (int i = (w - 1); i >= 0; i--) {
    bool erasing = true;
    for (int j = 0; j < (int)t2.size(); j++) {
      if (t2.at(j).at(i) == '#') {
        erasing = false;
      }
    }

    if (erasing == true) {
      for (int j = 0; j < (int)t2.size(); j++) {
        t2.at(j).erase(i, 1);
      }
    }
  }

  for (string row : t2) {
    cout << row << endl;
  }
  return 0;
}
