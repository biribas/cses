#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, X;
  cin >> N >> X;

  vector<int> coins(N);
  for (auto &c : coins) {
    cin >> c;
  }

  vector<int> dp(X + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= X; i++) {
    for (int j = 0; j < N; j++) {
      int k = i - coins[j];
      if (k < 0 || dp[k] == -1) continue;
      dp[i] = min(dp[i], dp[k] + 1);
    }
    if (dp[i] == INT_MAX) dp[i] = -1;
  }

  cout << dp[X] << endl;
}
