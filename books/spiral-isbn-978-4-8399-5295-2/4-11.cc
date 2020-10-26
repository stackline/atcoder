#include <bits/stdc++.h>
#include <list>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Do not use both "cin/cout" and "scanf/printf" at the same time.

  list<char> L;

  L.push_front('b'); // [b]
  L.push_back('c');  // [bc]
  L.push_front('a'); // [abc]

  cout << L.front(); // a
  cout << L.back();  // c

  L.pop_front();    // [bc]
  L.push_back('d'); // [bcd]

  cout << L.front();        // b
  cout << L.back() << endl; // d
  return 0;
}
