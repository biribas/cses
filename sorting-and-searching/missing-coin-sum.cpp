#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  int n;
  cin >> n;
  
  vector<ull>coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  
  sort(coins.begin(), coins.end());
  
  ull subset_sum = 1;

  for (auto coin : coins) {
    if (coin > subset_sum) break;
    subset_sum += coin;
  }
  
  cout << subset_sum << endl;
  return 0;
}
