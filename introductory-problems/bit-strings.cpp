#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull power(ull a, ull b, ull m) {
  ull result = 1;
  while (b > 0) {
    if (b & 1) result = (result * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  ull n;
  cin >> n;
  cout << power(2, n, 1000000007) << endl;
}
