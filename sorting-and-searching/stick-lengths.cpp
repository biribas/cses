#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  int n;
  cin >> n;
  
  vector<ll>sticks(n);
  for (int i = 0; i < n; i++)
    cin >> sticks[i];
  
  sort(sticks.begin(), sticks.end());
  
  ll median = sticks[n / 2];
  ull sum = 0;
  for (ll stick : sticks)
    sum += abs(median - stick);
  
  cout << sum << endl;
  return 0;
}
