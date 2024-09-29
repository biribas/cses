#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  int n, m, diff;
  cin >> n >> m >> diff;
  
  int desired_size[n];
  int apartment_size[m];

  for (int i = 0; i < n; i++)
    cin >> desired_size[i];
  for (int i = 0; i < m; i++)
    cin >> apartment_size[i];
  
  sort(desired_size, desired_size + n);
  sort(apartment_size, apartment_size + m);
  
  int i = 0, j = 0, result = 0;

  while (i < n && j < m) {
    if (abs(desired_size[i] - apartment_size[j]) <= diff) {
      result++;
      i++; j++;
    }
    else if (desired_size[i] < apartment_size[j]) {
      i++;
    }
    else {
      j++;
    }
  }
  
  cout << result << endl;
  return 0;
}
