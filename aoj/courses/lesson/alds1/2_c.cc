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
