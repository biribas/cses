#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int index;
  pair<int, int> interval;
} range;

typedef bool(*compare_func)(const range&, const range&);

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

void merge(vector<range> &ranges, int l, int mid, int r, vector<int> &count, compare_func cmp) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  
  vector<range>L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = ranges[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = ranges[mid + 1 + i];
  
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (cmp(L[i], R[j])) {
      ranges[k++] = L[i++];
    }
    else {
      count[R[j].index] += n1 - i;
      ranges[k++] = R[j++];
    }
  }
  
  while (i < n1) ranges[k++] = L[i++];
  while (j < n2) ranges[k++] = R[j++];
}

void merge_sort_aux(vector<range> &ranges, int l, int r, vector<int> &count, compare_func cmp) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  merge_sort_aux(ranges, l, mid, count, cmp);
  merge_sort_aux(ranges, mid + 1, r, count, cmp);
  merge(ranges, l, mid, r, count, cmp);
}

void merge_sort(vector<range> &ranges, vector<int> &count, compare_func cmp) {
  merge_sort_aux(ranges, 0, ranges.size() - 1, count, cmp);
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

  vector<int>contains(n);
  merge_sort(ranges, contains, sort_by_first);
  
  for (auto v : contains) cout << v << " ";
  cout << endl;

  vector<int>contained(n);
  merge_sort(ranges, contained, sort_by_second);

  for (auto v : contained) cout << v << " ";
  cout << endl;

  return 0;
}
