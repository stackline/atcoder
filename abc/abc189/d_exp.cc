#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(stack<string> st) {
  // ベースケース
  //
  // * f(S1,...,Sn) = f(S1,...,Sn-1) で f(S1) に変換していくパターン
  //   * このパターンは1パターンしかない。
  //   * Sn、x[n]、y[n-1] の値のとり方は以下の1パターンとなる。
  //     * Sn = AND の時 x[n] = true  && y[n-1] = true
  //     * Sn = OR  の時 x[n] = false || y[n-1] = false
  // * 上記以外のパターンは Sn = OR かつ x[n] = true の時のパターンである。
  //   * この時、y[n-1] は true/false どちらでもよい。
  //   * y[n-1] の取りうるパターンは 2**n である。
  //   * このケースは再帰ステップの "OR" 側で pow(2, exponent) で加算している。
  //     * また、Sn-1 や Sn-2 が "OR" の場合にケース数を重複カウントすることはない。
  //     * x[n] = true の場合に y[n-1] が取りうるケースは 2**n である。
  //     * Sn-1 や Sn-2 が "OR" の場合、pow(2, exponent) でケースをカウントするが、
  //       このケースは x[n] = false となるケースであり、x[n] = true となる場合のケースとは
  //       別でカウントされる。
  //
  if ((ll)st.size() == 0) {
    return 1;
  }

  // 再帰ステップ
  string s = st.top();
  st.pop();
  if (s == "AND") { // AND
    return f(st);
  } else { // OR
    // x[0] で開始時に2分岐を行う。
    // stack に残っているサイズ分、2分岐を繰り返す。
    // exponent は上記2つを合計した数である。
    ll exponent = (ll)st.size() + 1;
    ll pow_num = 1;
    for (int i = 0; i < exponent; i++) {
      pow_num *= 2;
    }
    return pow_num + f(st);
  }
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  stack<string> st;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st.push(s);
  }
  // ### 入力例1
  // n=2
  // AND
  // OR
  //
  // * y[n] = true の場合
  //   * S[n] = AND の場合
  //     * y[n-1] && x[n] = y[n]
  //       * (y[n-1], x[n]) = (true,  true)
  //   * S[n] = OR の場合
  //     * y[n-1] || x[n] = y[n]
  //       * (y[n-1], x[n]) = (false, true)
  //       * (y[n-1], x[n]) = (true,  true)
  //       * (y[n-1], x[n]) = (true,  false)
  //
  // y[n] = f(S[1],...,S[n]) = true とする。
  //
  // * S[n] = AND の場合
  //   * 取りうるパターン
  //     * (y[n-1] = true) && (x[n] = true)
  //   * 取りうるパターンより y[n], y[n-1] は以下となる。
  //     * y[n]   = f(S[1],...,S[n])   = true
  //     * y[n-1] = f(S[1],...,S[n-1]) = true
  //   * 上の式より以下の式が成り立つ。
  //     * f(S[1],...,S[n]) = f(S[1],...,S[n-1])
  // * S[n] = OR の場合
  //   * 取りうるパターン
  //     * (y[n-1] = true)  || (x[n] = true)
  //     * (y[n-1] = false) || (x[n] = true)
  //     * (y[n-1] = true)  || (x[n] = false)
  //   * x[n] = false の場合
  //     * f(S[1],...,S[n])   = y[n]   = true
  //     * f(S[1],...,S[n-1]) = y[n-1] = true
  //       * これより f(S[1],...,S[n]) = f(S[1],...,S[n-1])
  //   * x[n] = true の場合
  //     * f(S[1],...,S[n])   = y[n]   = true
  //     * f(S[1],...,S[n-1]) = y[n-1] = false
  //     * f(S[1],...,S[n-1]) = y[n-1] = true
  //       * y[n-1] の値は true/false どちらでもよい。
  //       * y[n-1] の段階で true/false のどちらかになるパターンは全部で 2**n である。
  //         * n=2 の場合
  //           * n=0 つまり x[0] --> y[0] = true/false の2通り
  //           * n=1 つまり x[1] --> y[1] = y[0] * 2通り = 4通り
  //   * x[n] = true の場合、false の場合を合わせると、以下の式となる。
  //     *  f(S[1],...,S[n])
  //          = f(S[1],...,S[n-1]) // x[n] = false の場合
  //          + 2**n               // x[n] = true の場合
  //

  cout << f(st) << endl;
  return 0;
}
