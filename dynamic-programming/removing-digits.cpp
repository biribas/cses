#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll N;
  cin >> N;

  vector<ll> dp(N + 1, INT_MAX);
  dp[0] = 0;

  for (ll i = 1; i <= N; i++) {
    ll num = i;
    while (num != 0) {
      ll d = num % 10;
      dp[i] = min(dp[i], dp[i - d] + 1);
      num /= 10;
    }
  }
  cout << dp[N] << endl;
}
