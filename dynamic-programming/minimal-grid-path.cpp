#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  string answer = {grid[0][0]};
  vector<pair<int, int>> frontier = {{0, 0}};
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}};
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  for (int step = 1, end = 2 * n - 1; step < end; step++) {
    char min_char = CHAR_MAX;
    vector<pair<int, int>> next_frontier;
    next_frontier.reserve(n);

    for (auto [i, j] : frontier) {
      for (auto [dx, dy] : directions) {
        int ni = i + dx, nj = j + dy;
        if (ni < n && nj < n && !visited[ni][nj]) {
          visited[ni][nj] = true;
          if (grid[ni][nj] < min_char) {
            min_char = grid[ni][nj];
            next_frontier.clear();
          }
          if (grid[ni][nj] == min_char) {
            next_frontier.emplace_back(ni, nj);
          }
        }
      }
    }

    frontier = next_frontier;
    answer += min_char;
  }

  cout << answer << endl;
  return 0;
}
