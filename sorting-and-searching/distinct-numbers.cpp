#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  map<ull, int>mp;
  ull input;

  while (n--) {
    cin >> input;
    mp[input]++;
  }

  cout << mp.size() << endl;
  
  return 0;
}
