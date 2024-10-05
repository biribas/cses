#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
 
int solve(int customer, multiset<int>& tickets) {
  multiset<int>::iterator it = tickets.upper_bound(customer);
 
  if (it == tickets.begin()) return -1;

  int ans = *(--it);
  tickets.erase(it);
  return ans;
}
 
int main(void) {
  int n, m;
  cin >> n >> m;
 
  multiset<int>tickets;
 
  for (int i = 0, input; i < n; i++) {
    cin >> input;
    tickets.insert(input);
  }
  
  int customer;
  while (m--) {
    cin >> customer;
    cout << solve(customer, tickets) << endl;
  }
  
  return 0;
}
