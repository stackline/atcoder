#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  set<char> st;
  for (int i = 0; i < (int)S.size(); i++) {
    char c = S.at(i);
    st.insert(c);
  }

  for (int i = (int)'a'; i <= (int)'z'; i++) {
    char c = (char)i;
    if (st.find(c) == st.end()) {
      cout << c << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  return 0;
}
