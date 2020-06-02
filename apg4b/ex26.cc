#include <bits/stdc++.h>
using namespace std;

const int npos = (int) string::npos;
map<char, int> map_ci;
map<char, vector<int>> map_cvi;

int ctoi(char c) {
  if (isdigit(c)) {
    return c - '0';
  } else if (isalpha(c)) {
    if (map_ci.count(c)) {
      return map_ci[c];
    } else {
      cout << "ctoi error 1" << endl;
      exit(1);
    }
  } else {
    cout << "ctoi error 2" << endl;
    exit(1);
  }
}

vector<int> ctovi(char c) {
  if (isalpha(c)) {
    if (map_cvi.count(c)) {
      return map_cvi[c];
    } else {
      cout << "ctovi error 1" << endl;
      exit(1);
    }
  } else {
    cout << "ctovi error 2" << endl;
    exit(1);
  }
}

// ### "1 + 2 + 3 - 4 - 5" を find_first_of で "+" 記号を起点に分割する
// * left  : 1
// * right : 2 + 3 - 4 - 5
// * 分割した右側の式の1文字目は、加算対象であるためOK
//
// ### "3 - 4 - 5" を find_last_of で "-" 記号を起点に分割する
// * left : 3 - 4
// * right : 5
// * 分割した右側の式の1文字目は、減算対象であるためOK
//
// ### "3 - 4 - 5" を find_first_of で "-" 記号を起点に分割した場合
// * left : 3
// * right : 4 - 5
// * 分割した右側の式を "4 - 5 = -1" と計算してしまう
// * 正しくは "(-4) + (-5) = (-9)" であるためNG
//
int calc(string expression) {
  int plus_pos = expression.find_first_of("+");
  int minus_pos = expression.find_last_of("-");

  // ベースケース
  if (plus_pos == npos && minus_pos == npos) {
    return ctoi(expression.at(0));
  }

  // 再帰ステップ
  if (plus_pos != npos) {
    string left = expression.substr(0, plus_pos);
    int left_num = calc(left);
    string right = expression.substr(plus_pos + 1);
    int right_num = calc(right);
    return left_num + right_num;
  } else if (minus_pos != npos) {
    string left = expression.substr(0, minus_pos);
    int left_num = calc(left);
    string right = expression.substr(minus_pos + 1);
    int right_num = calc(right);
    return left_num - right_num;
  } else {
    cout << "calc error" << endl;
    exit(1);
  }
}

vector<int> operate_vec(char op, vector<int> left, vector<int> right) {
  vector<int> result = left;
  for (int i = 0; i < (int) left.size(); i++) {
    if (op == '+') {
      result.at(i) = left.at(i) + right.at(i);
    } else if (op == '-') {
      result.at(i) = left.at(i) - right.at(i);
    } else {
      cout << "operate_vec error" << endl;
      exit(1);
    }
  }
  return result;
}

vector<int> calc_vec(string expression) {
  int plus_pos = expression.find_first_of("+");
  int minus_pos = expression.find_last_of("-");

  // ベースケース
  if (plus_pos == npos && minus_pos == npos) {
    char c = expression.at(0);

    // 変数の場合
    if (isalpha(c)) {
      return map_cvi[c];
    // 配列の場合
    } else {
      vector<int> v;
      for (int i = 0; i < (int) expression.size(); i++) {
        c = expression.at(i);
        if (isdigit(c) || isalpha(c)) {
          v.push_back(ctoi(c));
        }
      }
      return v;
    }
  }

  if (plus_pos != npos) {
    string left = expression.substr(0, plus_pos);
    vector<int> left_vi = calc_vec(left);
    string right = expression.substr(plus_pos + 1);
    vector<int> right_vi = calc_vec(right);
    return operate_vec('+', left_vi, right_vi);
  } else if (minus_pos != npos) {
    string left = expression.substr(0, minus_pos);
    vector<int> left_vi = calc_vec(left);
    string right = expression.substr(minus_pos + 1);
    vector<int> right_vi = calc_vec(right);
    return operate_vec('-', left_vi, right_vi);
  } else {
    cout << "calc error" << endl;
    exit(1);
  }
}

void do_int(string expression) {
  char variable_name = expression.at(0);
  string ex = expression.substr(2);
  int result = calc(ex);
  map_ci.insert(make_pair(variable_name, result));
}

void do_print_int(string expression) {
  int result = calc(expression);
  cout << result << endl;
}

void do_vec(string expression) {
  char variable_name = expression.at(0);
  string ex = expression.substr(2);
  vector<int> result = calc_vec(ex);
  map_cvi.insert(make_pair(variable_name, result));
}

void do_print_vec(string expression) {
  vector<int> result = calc_vec(expression);
  cout << "[ ";
  for (int i : result) {
    cout << i << " ";
  }
  cout << "]" << endl;
}

int main() {
  int N; // N <= 10
  cin >> N;

  vector<string> orders(N);
  vector<string> expressions(N);
  for (int i = 0; i < N; i++) {
    cin >> orders.at(i);

    while (1) {
      char c;
      cin >> c;
      if (c == ';') { break; }

      expressions.at(i) += c;
    }
  }

  for (int i = 0; i < N; i++) {
    string order = orders.at(i);
    string expression = expressions.at(i);

    if (order == "int") {
      do_int(expression);
    } else if (order == "print_int") {
      do_print_int(expression);
      // do_print_int(expression);
    } else if (order == "vec") {
      do_vec(expression);
    } else if (order == "print_vec") {
      do_print_vec(expression);
    }
  }

  return 0;
}
