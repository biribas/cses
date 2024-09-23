#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);

  ull n;
  cin >> n; 
  
  ull sum = 0;
  ull num;

  for (ull i = 0, limit = n - 1; i < limit; i++) {
    cin >> num;
    sum += num;
  }
  
  cout << ((n * (n + 1)) / 2) - sum << endl;
  return 0;
}
