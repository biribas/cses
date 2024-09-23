#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  unsigned long max = 1;
  unsigned long count = 1;

  for (int i = 1, n = s.length(); i < n; i++) {
    if (s[i - 1] == s[i]) {
      count++;
    }
    else {
      if (max < count) max = count;
      count = 1;
    }
  }

  if (max < count) max = count;
  
  cout << max << endl;

  return 0;
}
