#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init() {
  cin.tie(nullptr); // cin 時に cout を flush しない
  // cout << "hogehoge" << '\n';  // endl は改行後に flush するので、改行のみとする
  // ios::sync_with_stdio(false); // cin/cout と scanf/printf が混在する場合は注意
}

int main() {
  init();
  queue<string> q;

  q.push("red");    // { red }
  q.push("yellow"); // { red yellow }
  q.push("yellow"); // { red yellow yellow }
  q.push("blue");   // { red yellow yellow blue }
  cout << q.front() << " "; // red

  q.pop(); // { yellow yellow blue }
  cout << q.front() << " "; // yellow

  q.pop(); // { yellow blue }
  cout << q.front() << " "; // yellow

  q.pop(); // { blue }
  cout << q.front() << " "; // blue

  q.push("green"); // { blue green }
  cout << q.front() << " "; // blue

  q.pop(); // { green }
  cout << q.front() << '\n'; // green
  return 0;
}
