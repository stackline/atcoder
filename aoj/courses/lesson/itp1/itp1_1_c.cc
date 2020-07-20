#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int length, breadth;
  cin >> length >> breadth;

  int area = length * breadth;
  int perimeter = (length + breadth) * 2;

  cout << area << " " << perimeter << endl;
  return 0;
}
