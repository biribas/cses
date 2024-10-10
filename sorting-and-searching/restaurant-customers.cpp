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
  events.reserve(2 * n);
  
  for (int i = 0, in, out; i < n; i++) {
    cin >> in >> out;
    events.push_back({in, 1});
    events.push_back({out, -1});
  }
  
  sort(events.begin(), events.end());

  int customers = 0;
  int max_customers = 0;
  for (auto event : events) {
    customers += event.second;
    max_customers = max(max_customers, customers);
  }
  
  cout << max_customers << endl;
  return 0;
}
