#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, max_sum = 0;
  cin >> n;

  vector<int> values(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
    max_sum += values[i];
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= max_sum; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= values[i]) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - values[i]];
      }
    }
  }

  vector<int> answer;
  for (int j = 1; j <= max_sum; j++) {
    if (dp[n][j]) answer.push_back(j);
  }

  cout << answer.size() << endl;
  for (auto v : answer) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}
