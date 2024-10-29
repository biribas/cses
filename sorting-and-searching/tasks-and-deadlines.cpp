#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// If we perform T1 before T2: 
// reward = deadline(T1) - duration(T1) + deadline(T2) - duration(T1) - duration(T2)
//        = deadline(T1) + deadline(T2) - 2 * duration(T1) - duration(T2)
// Since the duration of the task performed earlier is subtracted more times from the reward
// as compared to the task performed later, we can conclude that the tasks with smaller duration
// should be performed first.

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  
  vector<pair<int, int>>tasks(n);
  for (auto &pair : tasks) {
    cin >> pair.first;
    cin >> pair.second;
  }
  
  sort(tasks.begin(), tasks.end());
  
  ll reward = 0;
  ll cur_time = 0;
  
  for (auto pair : tasks) {
    reward += pair.second - pair.first - cur_time;
    cur_time += pair.first;
  }
  
  cout << reward << endl;

  return 0;
}
