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

bool sort_by_second(const range &a, const range &b) {
  if (a.interval.second != b.interval.second) {
    return a.interval.second < b.interval.second;
  }
  return a.interval.first > b.interval.first;
}

void merge(vector<range> &ranges, int l, int mid, int r, vector<int> &contains, vector<int> &contained) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  
  vector<range>L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = ranges[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = ranges[mid + 1 + i];
  
  int contained_count = 0;
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (sort_by_first(L[i], R[j])) {
      contained[L[i].index] += contained_count;
      ranges[k++] = L[i++];
    }
    else {
      contains[R[j].index] += n1 - i;
      ranges[k++] = R[j++];
      contained_count++;
    }
  }
  
  while (i < n1) {
    contained[L[i].index] += contained_count;
    ranges[k++] = L[i++];
  }
  while (j < n2) {
    ranges[k++] = R[j++];
  }
}

void merge_sort_aux(vector<range> &ranges, int l, int r, vector<int> &contains, vector<int> &contained) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  merge_sort_aux(ranges, l, mid, contains, contained);
  merge_sort_aux(ranges, mid + 1, r, contains, contained);
  merge(ranges, l, mid, r, contains, contained);
}

void merge_sort(vector<range> &ranges, vector<int> &contains, vector<int> &contained) {
  merge_sort_aux(ranges, 0, ranges.size() - 1, contains, contained);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<range>ranges(n);
  for (int i = 0; i < n; i++) {
    cin >> ranges[i].interval.first >> ranges[i].interval.second;
    ranges[i].index = i;
  }
  sort(ranges.begin(), ranges.end(), sort_by_second);

  vector<int>contains(n), contained(n);
  merge_sort(ranges, contains, contained);
  
  for (auto v : contains) cout << v << " ";
  cout << endl;

  for (auto v : contained) cout << v << " ";
  cout << endl;

  return 0;
}
