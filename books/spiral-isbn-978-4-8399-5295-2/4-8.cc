#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  // cin で標準入力を読み取る際に cout を flush しない
  cin.tie(nullptr);
  // NOTE: cin/cout と scanf/printf を両方利用する場合は注意
  // ios::sync_with_stdio(false);
}

int main() {
  init();
  stack<int> S;

  S.push(3); // { 3 }
  S.push(7); // { 7, 3 }
  S.push(1); // { 1, 7, 3 }
  cout << S.size() << " "; // 3
  cout << S.top() << " ";  // 1

  S.pop(); // { 7, 3 }
  cout << S.top() << " "; // 7

  S.pop(); // { 3 }
  cout << S.top() << " "; // 3

  S.push(5); // { 5, 3 }
  cout << S.top() << " "; // 5

  S.pop(); // { 3 }
  cout << S.top() << endl; // 3

  return 0;
}
