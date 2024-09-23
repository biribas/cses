#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  
  ull n;
  cin >> n;
  
  // 1 x 1 chessboard
  cout << 0 << endl;

  ull total = 0;
  ull constraint = 0;
  
  // 2 x 2 to n x n chessboard
  for (ull i = 2; i <= n; i++) {
    total = (i * i) * (i * i - 1) >> 1;
    constraint += 8 * (i - 2); 
    cout << total - constraint << endl;
  }

  return 0;
}
