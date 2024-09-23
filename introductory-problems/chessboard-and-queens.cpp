#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve_aux(vector<string> board, ll n, ll row, vector<bool> occupied_cols,
             vector<bool> primary_diagonals, vector<bool> secondary_diagonals) {
  if (row == n)
    return 1;

  ll ans = 0;

  for (ll col = 0; col < n; col++) {
    if (board[row][col] == '*' || 
        occupied_cols[col] ||
        primary_diagonals[row - col + n - 1] || 
        secondary_diagonals[row + col]
      ) {
      continue;
    }
    
    occupied_cols[col] = primary_diagonals[row - col + n - 1] = secondary_diagonals[row + col] = true;
    ans += solve_aux(board, n, row + 1, occupied_cols, primary_diagonals, secondary_diagonals);
    occupied_cols[col] = primary_diagonals[row - col + n - 1] = secondary_diagonals[row + col] = false;
  }

  return ans;
}

ll solve(vector<string> board, int n) {
  vector<bool> occupied_cols(n, false);
  vector<bool> primary_diagonals(2 * n - 1, false);
  vector<bool> secondary_diagonals(2 * n - 1, false);
  return solve_aux(board, n, 0, occupied_cols, primary_diagonals, secondary_diagonals);
}

int main(void) {
  ios::sync_with_stdio(false);

  ll n = 0;
  vector<string> board;
  string s;

  while (cin >> s) {
    board.push_back(s);
    n++;
  }
  
  cout << solve(board, n) << endl;
  return 0;
}
