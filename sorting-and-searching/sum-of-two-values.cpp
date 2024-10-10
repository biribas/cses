#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, target_sum;
  cin >> n >> target_sum;
  
  vector<pair<int, int>>values(n);

  for (int i = 0; i < n; i++) {
    cin >> values[i].first;
    values[i].second = i + 1;
  }
  
  sort(values.begin(), values.end());
  
  int i = 0, j = n - 1, sum;
  while (i < j) {
    sum = values[i].first + values[j].first;
    if (sum == target_sum) {
      cout << values[i].second << " " << values[j].second << endl;
      return 0;
    }

    if (sum < target_sum)
      i++;
    else
      j--;
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
