#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

#define MOD 1000000007

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> dp(n + 1);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6 && j <= i; j++) {
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }

  cout << dp[n] << endl;
}
