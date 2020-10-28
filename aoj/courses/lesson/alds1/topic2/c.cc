#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> bubble_sort(vector<string> C, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j >= i+1; j--) {
      int l = (int) C.at(j-1).at(1);
      int r = (int) C.at(j).at(1);
      if (l > r) {
        swap(C.at(j-1), C.at(j));
      }
    }
  }
  return C;
}

vector<string> selection_sort(vector<string> C, int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      int j_value = (int) C.at(j).at(1);
      int minj_value = (int) C.at(minj).at(1);
      if (j_value < minj_value) {
        minj = j;
      }
    }
    swap(C.at(i), C.at(minj));
  }
  return C;
}

void print_vector(vector<string> C, int N) {
  for (int i = 0; i < N; ++i) {
    cout << C.at(i);
    if (i < N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

// p.71 掲載の、ソート結果が安定かどうかを調べる O(N**4) のアルゴリズム
//
// * 引数 in  は安定ソートなアルゴリズムでソートした配列
// * 引数 out は安定しているかどうかを判定したい配列
// * in out ともに、ある1つの配列にアルゴリズムを用いてソートしたもの
// * データ例
//   * ソート前
//     * H4 C9 S4 D2 C3
//   * ソート後
//     * in  = 安定なソート結果   : D2 C3 H4 S4 C9
//     * out = 非安定なソート結果 : D2 C3 S4 H4 C9
// * 以下を全て満たす場合 is_stable = false と判定する
//   * in[i].value == in[j].value         // 安定ソートで2枚のカードの数字が等しい
//   * in[i] == out[b] && in[j] == out[a] // inの配列とoutの配列で要素の位置が逆転している
// * データ例に当てはめると
//   * in[2].value == in[3].value && in[2] == out[3] && in[3] == out[2] が true となる
//   * in では要素番号で 2->3 と並んでいた要素が、out では要素番号で 3->2 と並び、安定していない
//
void print_stable_condition(vector<string> origin, vector<string> sorted, int N) {
  bool stable = true;
  for (int i = 0; i < N-1; i++) {
    string l_card = sorted.at(i);
    string r_card = sorted.at(i+1);

    // カードの数字が同じ場合に、絵柄の並びもソート前と同じであること
    // 以下の例では H4 と S4 の並び順について、ソート後も H4, S4 の順番に並んでいることを確認する
    //
    //   before: H4 C9 S4 D2 C3
    //   after: D2 C3 H4 S4 C9
    //
    if (l_card.at(1) == r_card.at(1)) {
      auto l_itr = find(origin.begin(), origin.end(), l_card);
      auto r_itr = find(origin.begin(), origin.end(), r_card);

      // ソート後は L->R の順番にカードが並んでいるに関わらず
      // ソート前は R->L の順番にカードが並んでいる場合、安定していないと判断
      if (l_itr > r_itr) {
        stable = false;
        break;
      }
    }
  }
  cout << (stable ? "Stable" : "Not stable") << endl;
}

int main() {
  int N;
  cin >> N;
  vector<string> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }

  vector<string> b_sorted = bubble_sort(C, N);
  print_vector(b_sorted, N);
  print_stable_condition(C, b_sorted, N);

  vector<string> s_sorted = selection_sort(C, N);
  print_vector(s_sorted, N);
  print_stable_condition(C, s_sorted, N);
  return 0;
}
