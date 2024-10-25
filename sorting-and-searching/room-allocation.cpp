#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int arrival;
  int departure;
  int index;
} timing;

typedef struct {
  int departure;
  int number;
} room;

struct cmp_rooms {
  bool operator()(room &a, room &b) {
    return a.departure > b.departure;
  }
};

bool cmp_timings(timing &a, timing &b) {
  return a.arrival < b.arrival;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<timing> timings(n);
  for (int i = 0; i < n; i++) {
    cin >> timings[i].arrival;
    cin >> timings[i].departure;
    timings[i].index = i;
  }

  sort(timings.begin(), timings.end(), cmp_timings);
  
  vector<int>answer(n);
  priority_queue<room, vector<room>, cmp_rooms> occupied_rooms;
  
  int rooms_used = 0;
  for (int i = 0; i < n; i++) {
    if (occupied_rooms.empty() || occupied_rooms.top().departure >= timings[i].arrival) {
      rooms_used++;
      occupied_rooms.push({timings[i].departure, rooms_used});
      answer[timings[i].index] = rooms_used;
    }
    else {
      int free_room = occupied_rooms.top().number;
      occupied_rooms.pop();
      occupied_rooms.push({timings[i].departure, free_room});
      answer[timings[i].index] = free_room;
    }
  }
  
  cout << rooms_used << endl;
  for (int v : answer) cout << v << " ";
  cout << endl;

  return 0;
}
