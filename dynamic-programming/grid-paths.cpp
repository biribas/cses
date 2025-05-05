#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll N;
  cin >> N;

  vector<vector<char>> maze(N + 1, vector<char>(N + 1));
  for (int i = 0; i <= N; i++) {
    maze[0][i] = '*';
    maze[i][0] = '*';
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> maze[i][j];
    }
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (maze[i][j] == '*') continue;
      if (i == 1 && j == 1) dp[i][j] = 1;
      else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[N][N] << endl;
}
