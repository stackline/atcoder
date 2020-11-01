#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  stack<int> s1;
  stack<pair<int, int>> s2;

  int sum = 0;
  // 自身の解答 d.cc と d2.cc は、x 座標を線の始点と終点とした。
  // 例えば、入力例の1文字目が "\" の場合、始点を (x,y)=(0,20000)、終点を (x,y)=(1,19999) とする。
  //
  // 解答例は "\" が登場する位置を x 座標とした。
  // 例えば、入力例の1文字目が "\" の場合、x=0 は "\"
  // 入力例の2文字目が "/" の場合、x=1 は "/" と捉える。
  for (int i = 0; i < static_cast<int>(s.size()); i++) {
    char c = s.at(i);
    if (c == '\\') {
      s1.push(i);
    } else if (c == '/' && s1.size() > 0) {
      // ### stack が0件の場合
      //    _/
      // __/
      // 上記のように一度も下り坂が無い場合、谷が作られないため、水たまりが出来ない。
      //
      // ### stack が1件以上の場合
      // \    _/
      //  \__/
      // 上記のように一度以上下り坂が存在する場合、
      // 「上り坂の x 座標」と「stack から取り出した直近の下り坂の x 座標」から、
      // 同じ y 座標 = 同じ高さに存在する水たまりの面積が算出できる。
      int j = s1.top();
      s1.pop();

      // 水たまりの総面積
      sum += i - j;
      // 各水たまりの面積
      // x 座標が j < x < i に存在する水たまりを、x 座標が j から i の水たまりに統合する。
      //
      // ### データ例1
      // 以下の場合、(2) の水たまりの面積を s2 から取り出し (1) に統合する。
      //
      //  \       /
      //   \     / --> (1) j から i の水たまり
      //    \___/  --> (2) j+1 から i-1 の水たまり
      //
      // また、x 座標が j-1 から i+1 の水たまり (3) が存在した場合は、
      // (1) も (2) 同様に (3) に統合される。
      //
      // ### データ例2
      // x 座標が j から i の水たまりが存在する。
      // x 座標が i から k の水たまりが存在する。
      // j < i < k である。
      //
      //   \_/\_/
      //
      // この場合、x 座標が i から k の水たまりの面積を計算する際、
      //
      //   s2.top().first > j という判定式について、
      //   左辺は x 座標 j を表す。
      //   右辺は x 座標 i を表す。
      //
      // j < i < k という前提条件より j > i は成立しないため、
      // 判定式は false となる。
      //
      int a = i - j;
      while (s2.size() > 0 && s2.top().first > j) {
        a += s2.top().second;
        s2.pop();
      }
      s2.push(make_pair(j, a));
    }
  }

  vector<int> ans;
  while (s2.size() > 0) {
    ans.push_back(s2.top().second);
    s2.pop();
  }
  // 最後の水たまりから順番にコンテナに詰めたので、逆順にソートする
  reverse(ans.begin(), ans.end());

  cout << sum << endl;
  cout << ans.size();
  for (int i = 0; i < static_cast<int>(ans.size()); i++) {
    cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
