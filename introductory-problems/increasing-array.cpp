#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  ull n, prev, cur;
  ull result = 0;

  cin >> n;
  cin >> prev;

  for (ull i = 1; i < n; i++) {
    cin >> cur;
    if (prev > cur) {
      result += prev - cur;
    } 
    else {
      prev = cur;
    }
  }
  
  cout << result << endl;
  
  return 0;
}
