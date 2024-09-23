#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve_aux(ll *apples, int n, ll sum1, ll sum2, int idx) {
  if (idx == n) {
    return abs(sum1 - sum2);
  }
  
  ll pick = solve_aux(apples, n, sum1 + apples[idx], sum2, idx + 1);
  ll not_pick = solve_aux(apples, n, sum1, sum2 + apples[idx], idx + 1);

  return min(pick, not_pick);
}

ll solve(ll *apples, ll n) {
  return solve_aux(apples, n, 0, 0, 0);
}

int main(void) {
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll apples[n];
  for (ll i = 0; i < n; i++) {
    cin >> apples[i];
  }
  
  cout << solve(apples, n) << endl;

  return 0;
}

