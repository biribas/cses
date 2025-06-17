#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> v1(n + 1), v2(m + 1);
  for (int i = 1; i <= n; i++) cin >> v1[i];
  for (int i = 1; i <= m; i++) cin >> v2[i];

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v1[i] == v2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int i = n, j = m;
  vector<int> result;
  while (i > 0 && j > 0) {
    if (v1[i] == v2[j]) {
      result.push_back(v1[i]);
      i--; j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    }
    else {
      j--;
    }
  }

  cout << dp[n][m] << endl;
  for (int i = result.size() - 1; i >= 0; i--) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
