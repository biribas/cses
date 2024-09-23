#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

void hanoi(ull src, ull dest, ull aux, ull n) {
  if (n == 0) return;
  hanoi(src, aux, dest, n - 1);
  cout << src << " " << dest << endl;
  hanoi(aux, dest, src, n - 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  ull n;
  cin >> n;
  
  cout << (1 << n) - 1 << endl;
  hanoi(1, 3, 2, n);
  return 0;
}
