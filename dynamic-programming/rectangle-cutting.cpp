#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> dp(h + 1, vector<int>(w + 1, INT_MAX));
  for (int i = 1; i <= h; i++) dp[i][1] = i - 1;
  for (int j = 1; j <= w; j++) dp[1][j] = j - 1;

  for (int i = 2; i <= h; i++) {
    for (int j = 2; j <= w; j++) {
      if (i == j) dp[i][j] = 0;

      // cut horizontally
      for (int k = 1, n = i >> 1; k <= n; k++)
        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);

      // cut vertically
      for (int k = 1, n = j >> 1; k <= n; k++)
        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
    }
  }

  cout << dp[h][w] << endl;
  return 0;
}
