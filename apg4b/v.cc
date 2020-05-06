#include <bits/stdc++.h>
using namespace std;

int sum_range(int a, int b) {
  if (a == b) {
    return a;
  }

  int sum = sum_range(a + 1, b);
  return sum + a;
}

void do_sum_range() {
  // sum_range
  cout << "### sum_range" << endl;
  cout << sum_range(3, 7) << endl; // 25
  cout << sum_range(0, 4) << endl; // 10
  cout << sum_range(5, 8) << endl; // 26
}

int my_array_sum(vector<int> &data) {
  if (data.size() == 1) {
    return data.at(0);
  }

  int last = data.back();
  data.pop_back();
  return my_array_sum(data) + last;
}

void do_my_array_sum() {
  vector<int> a = {0, 3, 9, 1, 5};
  cout << "### my_array_sum" << endl;
  cout << my_array_sum(a) << endl; // 18
}

int array_sum_from_i(vector<int> &data, int i) {
  if (i == (int)data.size()) {
    return 0;
  }
  return data[i] + array_sum_from_i(data, i + 1);
}

int array_sum(vector<int> &data) {
  return array_sum_from_i(data, 0);
}

void do_array_sum() {
  vector<int> a = {0, 3, 9, 1, 5};
  cout << "### array_sum" << endl;
  cout << array_sum(a) << endl; // 18
}

bool has_divisor(int N, int i) {
  if (i == N) {
    return false;
  }
  if (N % i == 0) {
    return true;
  }

  return has_divisor(N, i + 1);
}

bool is_prime(int N) {
  if (N == 1) {
    return false;
  }
  if (N == 2) {
    return true;
  }
  return !has_divisor(N, 2);
}

void do_is_prime() {
  cout << "### is_prime" << endl;
  cout << is_prime(1) << endl;  // 0
  cout << is_prime(2) << endl;  // 1
  cout << is_prime(12) << endl; // 0
  cout << is_prime(13) << endl; // 1
  cout << is_prime(57) << endl; // 0
}

vector<int> reverse_array_from_i(vector<int> &a, int i) {
  int a_size = a.size();
  if (i == a_size) {
    vector<int> x(a_size, 0);
    return x;
  }

  int num = a[i];
  vector<int> x = reverse_array_from_i(a, i + 1);
  x[a_size - i - 1] = num;
  return x;
}

vector<int> reverse_array(vector<int> &a) {
  return reverse_array_from_i(a, 0);
}

void do_reverse_array() {
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = reverse_array(a);
  cout << "### reverse_array" << endl;
  for (int i = 0; i < (int)b.size(); i++) {
    // 5
    // 4
    // 3
    // 2
    // 1
    cout << b.at(i) << endl;
  }
}

int main() {
  do_sum_range();
  do_my_array_sum();
  do_array_sum();
  do_is_prime();
  do_reverse_array();
  return 0;
}
