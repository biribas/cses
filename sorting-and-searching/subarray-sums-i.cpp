#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull solve(vector<ull> &numbers, ull x) {
  ull cur_sum = 0;
  ull result = 0;

  for (int i = 0, j = 0, n = numbers.size(); j < n; j++) {
    cur_sum += numbers[j];

    while (cur_sum > x && i < j) {
      cur_sum -= numbers[i++];
    }

    if (cur_sum == x) result++;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ull n, x;
  cin >> n >> x;
  
  vector<ull>numbers(n);
  for (auto &num : numbers) {
    cin >> num;
  }

  cout << solve(numbers, x) << endl;
  return 0;
}
