#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pair<ull, ull>> dp(1e6 + 1);
  dp[1] = {1, 1};

  for (int i = 2; i <= 1e6; i++) {
    dp[i].first = (4 * dp[i - 1].first + dp[i - 1].second) % MOD;
    dp[i].second = (dp[i - 1].first + 2 * dp[i - 1].second) % MOD;
  }

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    cout << (dp[n].first + dp[n].second) % MOD << endl;
  }

  return 0;
}
