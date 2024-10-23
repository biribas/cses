#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int index;
  pair<int, int> interval;
} range;

bool sort_by_first(const range &a, const range &b) {
  if (a.interval.first != b.interval.first) {
    return a.interval.first < b.interval.first;
  }
  return a.interval.second > b.interval.second;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<range>ranges(n);
  for (int i = 0; i < n; i++) {
    ranges[i].index = i;
    cin >> ranges[i].interval.first >> ranges[i].interval.second;
  }
  sort(ranges.begin(), ranges.end(), sort_by_first);
  
  vector<bool>contains(n);
  for (int i = n - 1, min_end = INT_MAX; i >= 0; i--) {
    contains[ranges[i].index] = ranges[i].interval.second >= min_end;
    min_end = min(min_end, ranges[i].interval.second);
  }
  
  for (auto v : contains) {
    cout << v << " ";
  }
  cout << endl;

  vector<bool>contained(n);
  for (int i = 0, max_end = 0; i < n; i++) {
    contained[ranges[i].index] = (ranges[i].interval.second <= max_end);
    max_end = max(max_end, ranges[i].interval.second);
  }

  for (auto v : contained) {
    cout << v << " ";
  }
  cout << endl;
  
  return 0;
}
