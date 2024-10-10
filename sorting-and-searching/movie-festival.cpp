#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  vector<pair<int, int>>events;
  events.reserve(n);
  
  for (int i = 0, begin, end; i < n; i++) {
    cin >> begin >> end;
    events.push_back({begin, end});
  }
  
  sort(events.begin(), events.end(), [](auto &left, auto &right) {
    return left.second < right.second;
  });
  
  int movies = 0, prev = 0;
  for (auto event : events) {
    if (event.first < prev) continue;
    movies++;
    prev = event.second;
  }
  
  cout << movies << endl;
  return 0;
}
