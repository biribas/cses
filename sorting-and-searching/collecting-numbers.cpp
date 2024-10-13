#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int solve(vector<int> &values, int n) {
  vector<int>indices(n + 1);
  for (int i = 1; i <= n; i++) {
    indices[values[i]] = i;
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (indices[i] > indices[i + 1])
      ans++;
  }

  return ans;
}

int main(void) {
  int n;
  cin >> n;

  vector<int>values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  cout << solve(values, n) << endl;

  return 0;
}
