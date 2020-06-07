#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  set<int> s;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    s.insert(n);
  }

  cout << s.size() << endl;
  return 0;
}
