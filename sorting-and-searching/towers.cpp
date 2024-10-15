#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  int n, cube;
  cin >> n;
  
  multiset<int>towers;

  while (n--) {
    cin >> cube;

    auto it = towers.upper_bound(cube);
    if (it == towers.end()) {
      towers.insert(cube);
      continue;
    }
    
    towers.erase(it);
    towers.insert(cube);
  }
  
  cout << towers.size() << endl;
  return 0;
}
