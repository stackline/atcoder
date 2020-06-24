#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> vi(100001, 0);

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    vi.at(a)++;
    sum += a;
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    ll from, to;
    cin >> from >> to;

    ll dif = vi.at(from) * (to - from);
    sum = sum + dif;

    vi.at(to) += vi.at(from);
    vi.at(from) -= vi.at(from);

    cout << sum << endl;
  }

  return 0;
}
