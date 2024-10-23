#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  
  vector<int>next_person(n);
  for (int i = 0; i < n; i++) {
    next_person[i] = i + 1;
  }
  next_person[n - 1] = 0;
  
  int cur = 0;
  while (n--) {
    int died = next_person[cur];
    cout << died + 1 << " ";
    next_person[cur] = next_person[died];
    cur = next_person[died];
  }
  cout << endl;

  return 0;
}
