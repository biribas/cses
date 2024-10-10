#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll solve(vector<ll> &values) {
  ll best_sum = numeric_limits<ll>::min();
  ll current_sum = 0;
  
  for (ll value : values) {
    current_sum = max(value, current_sum + value);
    best_sum = max(best_sum, current_sum);
  }
  
  return best_sum;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  vector<ll>values(n);
  for (int i = 0; i < n; i++)
    cin >> values[i];
    
  cout << solve(values) << endl;
  return 0;
}
