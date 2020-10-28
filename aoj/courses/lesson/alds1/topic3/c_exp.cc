#include <bits/stdc++.h>
#include <list>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  list<int> li;
  string s;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "insert") {
      cin >> x;
      li.push_front(x);
    } else if (s == "delete") {
      cin >> x;
      for (auto itr = li.begin(); itr != li.end(); itr++) {
        if (*itr == x) {
          li.erase(itr);
          break;
        }
      }
    } else if (s == "deleteFirst") {
      li.pop_front();
    } else if (s == "deleteLast") {
      li.pop_back();
    }
  }

  for (auto itr = li.begin(); itr != li.end(); itr++) {
    if (itr != li.begin()) {
      cout << " ";
    }
    cout << *itr;
  }
  cout << endl;
  return 0;
}
