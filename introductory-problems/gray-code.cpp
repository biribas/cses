#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  ull n;
  cin >> n;
  
  for (ull i = 0; i < 1ull << n; i++) {
    bitset<16> b(i ^ (i >> 1));
    cout << b.to_string().substr(16 - n) << endl;
  }

  return 0;
}
