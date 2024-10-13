#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int solve(vector<int> &values, vector<int> &indices, int n, int a, int b, int &ans) {
  set<pair<int, int>>updated_pairs;

  if (values[a] < n) updated_pairs.insert({values[a], values[a] + 1});
  if (values[b] < n) updated_pairs.insert({values[b], values[b] + 1});
  if (values[a] > 1) updated_pairs.insert({values[a] - 1, values[a]});
  if (values[b] > 1) updated_pairs.insert({values[b] - 1, values[b]});
  
  // Remove inversions caused by pairs to be updated
  for (auto pair : updated_pairs)
    ans -= indices[pair.first] > indices[pair.second];
  
  swap(values[a], values[b]);
  indices[values[a]] = a;
  indices[values[b]] = b;

  // Adds inversions cause by pairs that were updated
  for (auto pair : updated_pairs)
    ans += indices[pair.first] > indices[pair.second];
  
  return ans;
}

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<int>values(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
  }

  vector<int>indices(n + 1);
  for (int i = 1; i <= n; i++) {
    indices[values[i]] = i;
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans += indices[i] > indices[i + 1];
  }

  int a, b;
  while (m--) {
    cin >> a >> b;
    cout << solve(values, indices, n, a, b, ans) << endl;
  }

  return 0;
}
