#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> values(n);
  for (auto &v : values) {
    cin >> v;
  }

  set<int> answer;
  for (auto v : values) {
    vector<int> original(answer.begin(), answer.end());
    for (auto x : original) {
      answer.insert(v + x);
    }
    answer.insert(v);
  }

  cout << answer.size() << endl;
  for (auto v : answer) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}
