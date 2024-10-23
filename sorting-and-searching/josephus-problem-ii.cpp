#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;

  ordered_set<int>people;
  for (int i = 1; i <= n; i++) {
    people.insert(i);
  }

  int index = 0;
  while (people.size()) {
    index = (index + k) % people.size();
    int died = *people.find_by_order(index);
    people.erase(died);
    cout << died << " ";
  }
  cout << endl;

  return 0;
}
