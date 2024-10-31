#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i].first;
    values[i].second = i + 1;
  }
  sort(values.begin(), values.end());

  for (int i = 0; i < n - 1; i++) {
    int j = i + 1, k = n - 1;
    while (j < k) {
      int sum = values[i].first + values[j].first + values[k].first;
      if (sum == x) {
        cout << values[i].second << " " << values[j].second << " " << values[k].second << endl;
        return 0;
      }

      if (sum < x) j++;
      else k--;
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
