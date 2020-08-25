#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// x, y, z の中間の値
int med3(int x, int y, int z) {
  if (x < y) {
    if (y < z) {
      return y;
    } else {
      return (z < x ? x : z);
    }
  } else {
    if (z < y) {
      return y;
    } else {
      return (x < z ? x : z);
    }
  }
}

void quicksort(vector<int> &a, int left, int right) {
  cout << "left:   " << left << endl;
  cout << "right:  " << right << endl;
  cout << "target: ";
  for (int i = left; i <= right; i++) { cout << i << " "; }
  cout << endl;
  cout << "        ";
  for (int i = left; i <= right; i++) { cout << a.at(i) << " "; }
  cout << endl;

  if (left < right) {
    int i = left;
    int j = right;
    // 要素が8つある場合、かつ末尾から2つの要素を取り扱う場合、
    // 6 + (7 - 1) / 2 = 9 となり、要素数を超える
    // int pivot = med3(a.at(i), a.at(i + (j - 1) / 2), a.at(j));
    int pivot = med3(a.at(i), a.at((i + j) / 2), a.at(j));
    cout << "pivot:  " << pivot << endl;

    int loop_count_1st = 0;
    int loop_count_2nd = 0;
    while (1) {
      loop_count_1st++;
      while (a.at(i) < pivot) { i++; loop_count_2nd++; }
      while (a.at(j) > pivot) { j--; loop_count_2nd++; }

      if (i >= j) { break; }

      // a.at(i) と a.at(j) を交換
      int tmp = a.at(i);
      a.at(i) = a.at(j);
      a.at(j) = tmp;

      i++;
      j--;
    }

    cout << "loop_count_1st: " << loop_count_1st << endl;
    cout << "loop_count_2nd: " << loop_count_2nd << endl;

    cout << "### quicksort left" << endl;
    quicksort(a, left, i - 1); // 分割した左を再帰的にソート
    cout << "### quicksort right" << endl;
    quicksort(a, j + 1, right); // 分割した右を再帰的にソート
  }
}

int main() {
  // vector<int> v = {8, 4, 3, 7, 6, 5, 2, 1};
  vector<int> v = {5, 4, 3, 2, 1};

  cout << "input: ";
  for (auto i : v) { cout << i << " "; }
  cout << endl;

  cout << endl;
  cout << "### quicksort start" << endl;
  quicksort(v, 0, v.size() - 1);
  cout << endl;

  cout << "output: ";
  for (auto i : v) { cout << i << " "; }
  cout << endl;
  return 0;
}
