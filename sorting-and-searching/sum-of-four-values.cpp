#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;

  vector<int> values(n);
  for (auto &v : values) {
    cin >> v;
  }

  unordered_map<int, pair<int, int>> pairs_sums;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int complement = x - (values[i] + values[j]);
      if (pairs_sums.find(complement) == pairs_sums.end()) continue;

      cout << 
        i + 1 << " " <<
        j + 1 << " " <<
        pairs_sums[complement].first + 1 << " " <<
        pairs_sums[complement].second + 1 <<
      endl;

      return 0;
    }
    
    for (int j = i - 1; j >= 0; j--) {
      pairs_sums[values[i] + values[j]] = {i, j};
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
