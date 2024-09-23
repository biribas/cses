#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  ull n;
  cin >> n;
  
  ull count = 0;
  while (n > 0) {
    n /= 5;
    count += n;
  }
  
  cout << count << endl;
  return 0;
}
