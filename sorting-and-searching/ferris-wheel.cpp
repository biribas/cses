#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  int n, max_weight;
  cin >> n >> max_weight;
  
  int childern[n];
  for (int i = 0; i < n; i++)
    cin >> childern[i];
  
  sort(childern, childern + n);
  
  int lightest = 0, heviest = n - 1;
  int gondolas = 0;
  
  while (lightest <= heviest) {
    if (childern[lightest] + childern[heviest] <= max_weight) {
      lightest++;
    }
    heviest--;
    gondolas++;
  }
  
  cout << gondolas << endl;
  return 0;
}
