#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, X;
  cin >> N >> X;

  vector<int> price(N + 1), pages(N + 1);
  for (int i = 1; i <= N; i++) cin >> price[i];
  for (int i = 1; i <= N; i++) cin >> pages[i];

  vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= X; j++) {
      if (price[i] > j) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + pages[i]);
    }
  }

  cout << dp[N][X] << endl;
  return 0;
}
