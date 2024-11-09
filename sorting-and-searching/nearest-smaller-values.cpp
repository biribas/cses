#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  
  vector<int>numbers(n);
  for (auto &num : numbers) {
    cin >> num;
  }

  stack<pair<int, int>>monotonic_stack;
  monotonic_stack.push({0, 0});

  for (int i = 0; i < n; i++) {
    while (numbers[i] <= monotonic_stack.top().first) {
      monotonic_stack.pop();
    }
    cout << monotonic_stack.top().second << " ";
    monotonic_stack.push({numbers[i], i + 1});
  }
  
  cout << endl;
  return 0;
}
