#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull solve(ull y, ull x) {
  if (x > y) {
    if (x & 1) return x * x - y + 1;
    else return (x - 1) * (x - 1) + y;
  }
  else {
    if (y & 1) return (y - 1) * (y - 1) + x;
    else return y * y - x + 1;
  }
}

int main(void) {
  ios::sync_with_stdio(false);

  ull n, y, x;
  cin >> n;
  for (ull i = 0; i < n; i++) {
    cin >> y >> x;
    cout << solve(y, x) << endl;
  }
  
  return 0;
}
