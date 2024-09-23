#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  
  ull n;
  cin >> n;
  
  ull sum = n * (n + 1) >> 1;
  
  if (sum & 1) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  
  ull first;
  if (n & 1) {
    first = 4;
    cout << (n >> 1) + 1 << endl;
    cout << "1 2 ";
  }
  else {
    first = 1;
    cout << (n >> 1) << endl;
  }

  ull last = n;
  
  // First subset
  for (ull i = first, j = last; i < j; i+=2, j-=2) {
    cout << i << " " << j << " ";
  }
  cout << endl;

  cout << (n >> 1) << endl;
  if (n & 1) {
    cout << "3 ";
  }

  // Second subset
  for (ull i = first + 1, j = last - 1; i < j; i+=2, j-=2) {
    cout << i << " " << j << " ";
  }
  cout << endl;

  return 0;
}
