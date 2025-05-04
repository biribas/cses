#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, X;
  cin >> N >> X;

  vector<int> coins(N);
  for (auto &c : coins) {
    cin >> c;
  }

  vector<int> dp(X + 1, 0);
  dp[0] = 1;

  // By switching the order of the nested loops from the previous problem,
  // we now iterate over the coins first, then the DP table. This ensures
  // that each coin is only considered once per subproblem, preventing
  // duplicate combinations that differ only in order.
  for (int j = 0; j < N; j++) {
    for (int i = 1; i <= X; i++) {
      int k = i - coins[j];
      if (k < 0) continue;
      dp[i] = (dp[i] + dp[k]) % MOD;
    }
  }

  cout << dp[X] << endl;
}
