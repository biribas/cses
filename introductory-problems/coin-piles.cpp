#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

string solve(ull a, ull b) {
  if (a < b) swap(a, b);
  if (a > (b << 1)) return "NO";
  if ((a + b) % 3) return "NO";
  return "YES";
}

int main(void) {
  ios::sync_with_stdio(false);

  ull t, a, b;
  cin >> t;

  for (ull i = 0; i < t; i++) {
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }

  return 0;
}
