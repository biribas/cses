#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull power(ull a, ull b) {
  ull result = 1;
  while (b > 0) {
    if (b & 1) result *= a;
    a *= a;
    b >>= 1;
  }
  return result;
}

int solve(ull index) {
  int digits = 1;
  ull power_of_ten = 1;

  ull lower_bound = 0;
  ull upper_bound = 0;
  
  while (true) {
    upper_bound += 9 * digits * power_of_ten;
    if (upper_bound >= index) break;
    lower_bound = upper_bound;
    digits++;
    power_of_ten *= 10;
  }
  
  index -= lower_bound;   // Adjust index relative to the start of the current range
  index--;                // Decrease by 1 to account for 0-based indexing

  // The number that contains the index
  ull number = power_of_ten + index / digits;
  // Calculate which digit in the number is the result
  int position = (digits - 1) - index % digits;
  
  return (number / power(10, position)) % 10;
}

int main(void) {
  ios::sync_with_stdio(false);

  int q;
  ull index;

  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> index;
    cout << solve(index) << endl;
  }

  return 0;
}
