#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> arr(N);
  for (auto &v : arr) cin >> v;

  // dp[i][j] = number of ways to have arr[i] = j (1 <= j <= M)
  vector<vector<int>> dp(N, vector<int>(M + 2, 0));

  // Initialize the first element:
  // - If arr[0] is fixed (non-zero), only one valid way to start
  // - If arr[0] is 0, all values from 1 to M are initially valid
  if (arr[0] != 0) dp[0][arr[0]] = 1;
  else fill(dp[0].begin() + 1, dp[0].begin() + M + 1, 1);

  // Fill the DP table
  for (int i = 1; i < N; i++) {
    // Determine the range of values to consider for arr[i]
    // - If arr[i] is 0, try all values from 1 to M
    // - Otherwise, only consider the fixed value arr[i]
    int from = arr[i] == 0 ? 1 : arr[i];
    int to = arr[i] == 0 ? M : arr[i];

    for (int j = from; j <= to; j++) {
      // For each j, sum the number of ways to come from previous values
      // j-1, j, or j+1, respecting bounds (handled implicitly by dp size)
      for (int k = -1; k <= 1; k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % MOD;
      }
    }
  }

  // Sum all possible ways to end at position N - 1 for values from 1 to M
  int ans = 0;
  for (auto v : dp[N - 1]) {
    ans = (ans + v) % MOD;
  }

  cout << ans << endl;
  return 0;
}
