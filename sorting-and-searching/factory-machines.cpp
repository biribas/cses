#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;

// calculates sum(floor(M / ki)), where M is the minimum time
ull summation(vector<ull> &times, ull M) {
  ull result = 0;
  for (ull k : times) {
    result += M / k;
  }
  return result;
}

ull bs(ull l, ull r, vector<ull> &times, ull t) {
  ull result = 0;

  while (l <= r) {
    ull M = l + (r - l) / 2;
    if (summation(times, M) >= t) {
      result = M;
      r = M - 1;
    }
    else {
      l = M + 1;
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  
  vector<ull> times(n); 
  ull min_time = LONG_LONG_MAX;
  for (auto &k : times) {
    cin >> k;
    min_time = min(min_time, k);
  }
  
  cout << bs(0, min_time * t, times, t) << endl;
  return 0;
}
