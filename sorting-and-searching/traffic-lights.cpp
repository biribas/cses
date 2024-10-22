#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef struct {
  int prev, next;
  int pos;
} traffic_light;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x, n;
  cin >> x >> n;
  
  vector<pair<int, int>>sorted_lights(n);
  for (int i = 0; i < n; i++) {
    cin >> sorted_lights[i].first;
    sorted_lights[i].second = i;
  }
  sort(sorted_lights.begin(), sorted_lights.end());
  
  vector<int>new_index(n);
  for (int i = 0; i < n; i++) {
    new_index[sorted_lights[i].second] = i;
  }

  vector<traffic_light>lights(n + 2);
  lights[0] = {-1, 1, 0};
  lights[n + 1] = {n, -1, x};

  for (int i = 1; i <= n; i++) {
    lights[i] = {i - 1, i + 1, sorted_lights[i - 1].first};
  }

  int max_gap = 0;
  for (int i = 0; i <= n; i++) {
    max_gap = max(max_gap, lights[i + 1].pos - lights[i].pos);
  }
  
  vector<ull>gaps(n);
  gaps.back() = max_gap;
  
  for (int i = n - 1; i > 0; i--) {
    traffic_light to_del = lights[new_index[i] + 1];
    traffic_light &left = lights[to_del.prev];
    traffic_light &right = lights[to_del.next];
    left.next = to_del.next;
    right.prev = to_del.prev;

    max_gap = max(max_gap, right.pos - left.pos);
    gaps[i - 1] = max_gap;
  }
  
  for (int i = 0; i < n; i++) {
    cout << gaps[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
