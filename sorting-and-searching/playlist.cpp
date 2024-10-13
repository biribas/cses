#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int solve(vector<int> &values, int n) {
  map<int, int>last_occurrence;

  int ans = 0;
  for (int l = 0, r = 1; r <= n; r++) {
    l = max(l, last_occurrence[values[r]]);
    last_occurrence[values[r]] = r;
    ans = max(ans, r - l);
  }

  return ans;
}

int main(void) {
  int n;
  cin >> n;

  vector<int>values(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
  }

  cout << solve(values, n) << endl;

  return 0;
}
