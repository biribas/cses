#include <bits/stdc++.h>

using namespace std;

int main(void) {
  unsigned long long  n;
  cin >> n; 
  
  cout << n << " ";
  while (n != 1) {
    n = n % 2 ? 3 * n + 1 : n / 2;
    cout << n << " ";
  }

  cout << endl;
  return 0;
}
