// https://ja.wikipedia.org/wiki/IEEE_754
// https://ja.wikipedia.org/wiki/倍精度浮動小数点数
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MyDouble {
  const int FRACTION_BITS_SIZE = 52;
  const int EXPONENT_MAX = 1023;

  char sign;
  string exponent;
  string fraction;

  MyDouble(string s) {
    sign = build_sign(s);
    exponent = build_exponent(s);
    fraction = build_fraction(s);
  }

  void dump() {
    cout << "sign     : " << sign << endl;
    cout << "exponent : " << exponent << endl;
    cout << "fraction : " << fraction << endl;
    cout << "get()    : " << get() << endl;
  }

  string get() {
    int s = sign - '0';

    double num = 0.0;
    for (int i = 0; i < (int) fraction.size(); i++) {
      if (fraction.at(i) == '1') {
        double d = (double(1) / double(pow(2, i + 1)));
        num += d;
      }
    }
    double c = 1.0 + num;

    int b = 2;
    int q = convert_binary_number_to_integer(exponent) - EXPONENT_MAX;

    double result = pow(-1, s) * c * pow(b, q);
    cout << s << endl;
    cout << c << endl;
    cout << b << endl;
    cout << q << endl;
    return to_string(result);
  }

  void multiplication(MyDouble other) {
    // sign
    bool is_plus = ((sign == '0' && other.sign == '0') || (sign == '1' && other.sign == '1'));
    sign = (is_plus ? '0' : '1');

    // exponent
    int left_exponent = convert_binary_number_to_integer(exponent);
    int right_exponent = convert_binary_number_to_integer(other.exponent);
    int result_exponent = left_exponent + right_exponent - EXPONENT_MAX;
    exponent = convert_integer_to_binary_number(result_exponent);

    // fraction
    double left_fraction = convert_fraction_to_double(fraction);
    double right_fraction = convert_fraction_to_double(other.fraction);
    double result_fraction = left_fraction * right_fraction;

    string s = to_string(result_fraction);
    size_t decimal_separator_pos = s.find_first_of('.');

    int decimal_part = stoi(s.substr(decimal_separator_pos + 1));
    string decimal_part_binary_number = convert_decimal_to_binary_number(decimal_part);
    fraction = decimal_part_binary_number;
  }

  char build_sign(string s) {
    if (s.at(0) == '-') {
      return '1';
    } else {
      return '0';
    }
  }

  string build_exponent(string s) {
    size_t decimal_separator_pos = s.find_first_of('.');

    int integer_part = abs(stoi(s.substr(0, decimal_separator_pos)));
    string integer_part_binary_number = convert_integer_to_binary_number(integer_part);

    int exponent_without_bias = integer_part_binary_number.size() - 1;
    int exponent = exponent_without_bias + EXPONENT_MAX;

    return convert_integer_to_binary_number(exponent);
  }

  string build_fraction(string s) {
    size_t decimal_separator_pos = s.find_first_of('.');

    int integer_part = abs(stoi(s.substr(0, decimal_separator_pos)));
    string integer_part_binary_number = convert_integer_to_binary_number(integer_part);
    int decimal_part = stoi(s.substr(decimal_separator_pos + 1));
    string decimal_part_binary_number = convert_decimal_to_binary_number(decimal_part);
    string binary_number = integer_part_binary_number.substr(1) + decimal_part_binary_number;

    if ((int) binary_number.size() < FRACTION_BITS_SIZE) {
      while ((int) binary_number.size() < FRACTION_BITS_SIZE) {
        binary_number += '0';
      }
    }
    if ((int) binary_number.size() > FRACTION_BITS_SIZE) {
      binary_number = binary_number.substr(0, FRACTION_BITS_SIZE);
    }

    return binary_number;
  }

  string convert_integer_to_binary_number(int num) {
    string binary_number;

    while (1) {
      int remainder = num % 2;
      binary_number = to_string(remainder) + binary_number;

      int quotient = num / 2;
      if (quotient <= 1) {
        binary_number = to_string(quotient) + binary_number;
        break;
      }

      num = quotient;
    }
    return binary_number;
  }

  string convert_decimal_to_binary_number(int num) {
    int digit = to_string(num).length();
    int threshold = pow(10, digit);
    int fraction_bits = 0;
    string binary_number;

    while (1) {
      int product = num * 2;

      if (product > threshold) {
        num = product - threshold;
        binary_number = binary_number + '1';
      } else if (product < threshold) {
        num = product;
        binary_number = binary_number + '0';
      } else if (product == threshold) {
        binary_number = binary_number + '1';
        break;
      }

      fraction_bits++;
      if (fraction_bits == FRACTION_BITS_SIZE) {
        break;
      }
    }
    return binary_number;
  }

  int convert_binary_number_to_integer(string s) {
    reverse(s.begin(), s.end());

    int sum = 0;
    int base = 1;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s.at(i) == '1') {
        sum += base;
      }
      base *= 2;
    }

    return sum;
  }

  double convert_fraction_to_double(string fraction) {
    double num = 0.0;
    for (int i = 0; i < (int) fraction.size(); i++) {
      if (fraction.at(i) == '1') {
        double d = (double(1) / double(pow(2, i + 1)));
        num += d;
      }
    }
    double c = 1.0 + num;
    return c;
  }
};

int main() {
  // string s;
  // cin >> s;
  vector<string> vs;
  vs.push_back("2.625");
  vs.push_back("2.51");
  vs.push_back("100.0");
  // vs.push_back("40.625");
  // vs.push_back("0.625");
  // vs.push_back("-118.625");
  // vs.push_back("2.6875");

  for (string s : vs) {
    MyDouble my_double(s);
    cout << "### debug" << endl;
    cout << "s        : " << s << endl;
    my_double.dump();
    cout << endl;
  }

  double a = 2.51;
  double b = 100;
  int c = int(a * b);
  cout << "### pattern 1" << endl;
  cout << c << endl;
  cout << endl;

  MyDouble left("2.51");
  MyDouble right("100.0");
  left.multiplication(right);

  cout << "### pattern 2" << endl;
  cout << "left  : 2.51" << endl;
  cout << "right : 100.0" << endl;
  left.dump();
  cout << endl;

  int n = (int) stod(left.get());
  cout << left.get() << endl;
  cout << n << endl;
  return 0;
}
