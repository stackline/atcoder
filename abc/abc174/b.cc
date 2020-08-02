#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, D;
  cin >> N >> D;

  vector<ll> x(N);
  vector<ll> y(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
    cin >> y.at(i);
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    ll px = x.at(i);
    ll py = y.at(i);

    double z = sqrt(px * px + py * py);
    if (z <= D) {
      sum++;
    }
  }

  cout << sum << endl;
  return 0;
}
