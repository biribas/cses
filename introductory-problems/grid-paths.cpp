#include <bits/stdc++.h>

#define decode_dir(c)(c == 'U' ? 0 : c == 'D' ? 1 : c == 'L' ? 2 : 3)

using namespace std;
typedef unsigned long long ull;

typedef struct {
  int x;
  int y;
} direction_t;

direction_t adjacent[] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

direction_t diagonals[] = {
  {-1, -1}, {-1, 1}, {1, 1}, {1, -1}
};

bool wall[9][9] = {false};
string path;

bool is_valid(int i, int j) {
  // up and down squares are unvisited and left and right squares are visited
  if (wall[i - 1][j] && wall[i + 1][j] && !wall[i][j - 1] && !wall[i][j + 1])
    return false;
  
  // left and right squares are unvisited and up and down squares are visited
  if (!wall[i - 1][j] && !wall[i + 1][j] && wall[i][j - 1] && wall[i][j + 1])
    return false;
  
  // diagonal square is visited and diagonal neighbors are unvisited
  for (auto pair : diagonals) {
    if (wall[i + pair.x][j + pair.y] && !wall[i + pair.x][j] &&  !wall[i][j + pair.y])
      return false;
  }
  
  return true;
}

int solve_aux(int index, int i, int j) {
  if (wall[i][j]) return 0;

  // Final Position
  if (i == 7 && j == 1)
    return index == (int)path.length();
  
  if (!is_valid(i, j)) return 0;

  wall[i][j] = true;
  int ans = 0;

  if (path[index] != '?') {
    auto pair = adjacent[decode_dir(path[index])];
    ans = solve_aux(index + 1, i + pair.x, j + pair.y);
  } 
  else {
    for (auto pair : adjacent) {
      ans += solve_aux(index + 1, i + pair.x, j + pair.y);
    }
  }

  wall[i][j] = false;
  return ans;
}

ull solve(void) {
  for (int i = 0; i < 9; i++) {
    wall[i][0] = true;
    wall[i][8] = true;
    wall[0][i] = true;
    wall[8][i] = true;
  }
  return solve_aux(0, 1, 1);
}

int main(void) {
  ios::sync_with_stdio(false);

  cin >> path;
  cout << solve() << endl;
}
