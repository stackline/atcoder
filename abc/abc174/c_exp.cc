#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int K;
  cin >> K;

  int ans = 0;
  int remainder = 0;
  for (int i = 0; i < K; i++) {
    ans++;
    // 第1項 "7" と第2項 "77" の関係は a[2] = a[1] * 10 + 7 となる
    // 余りも同様であり、 第2項の余りは、第1項の余りに10を掛けたものに+7したものとなる
    //
    // 剰余はK未満となるため、「第1項の余りに10を掛けたものに+7したもの」の値がK以上の場合を想定して、
    // mod(K) を求める
    remainder = (remainder * 10 + 7) % K;
    // Kの倍数の場合、余りが0となるので、ここで試行を終了する
    if (remainder == 0) { break; }
    // K回試行して、Kの倍数が登場しなかった場合は、存在しないと判断して-1とする
    //
    // NOTE:
    // mod(K) の値は K-1 以下の値を取りうる
    //
    // K=9 の場合、余りは 7 -> 5 -> 3 -> 1 -> 8 -> 6 -> 4 -> 2 -> 0 と9種類のユニークな値を経由して 0 に到達する。
    // 毎回 0〜K-1 の値の中でユニークな値に遷移し、最後に0に到達するため、これが試行回数が最大となる。
    //
    // K=6 の場合、余りは 1 -> 5 -> 3 -> 1 -> 5 -> 3 とループし、0 に到達することがない。
    // 剰余の値として1回目と同じ値が4回目に登場する。
    // 剰余の値は以下の式を元に算出しているため、4回目以降も1〜3回目と同じインプットで、
    // 同じアウトプットが算出されるため、同じ数の遷移を辿ることになる。
    //
    //   r[n+1] = (r[n] * 10 + 7) % K
    //
    if (i == K-1) { ans = -1; }
  }

  cout << ans << endl;
  return 0;
}
