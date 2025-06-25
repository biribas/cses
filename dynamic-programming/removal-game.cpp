#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Grid3D {
  int X, Y, Z;
  std::vector<ll> data;

  Grid3D(int x, int y, int z) : X(x), Y(y), Z(z), data(x * y * z) {}

  ll& at(int i, int j, int k) {
    return data[i * Y * Z + j * Z + k];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int cur_player = N % 2 ? 0 : 1;
  Grid3D dp(N, N, 2);

  vector<ll> numbers(N);
  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
    dp.at(i, i, cur_player) = numbers[i];
  }
  cur_player = !cur_player;

  // Fill upper triangular matrix
  for (int k = 1; k < N; k++) {
    for (int i = 0, j = k; j < N; i++, j++) {
      ll v1 = numbers[i] + dp.at(i + 1, j, cur_player);
      ll v2 = numbers[j] + dp.at(i, j - 1, cur_player);

      if (v1 > v2) {
        dp.at(i, j, cur_player) = v1;
        dp.at(i, j, !cur_player) = dp.at(i + 1, j, !cur_player);
      }
      else {
        dp.at(i, j, cur_player) = v2;
        dp.at(i, j, !cur_player) = dp.at(i, j - 1, !cur_player);
      }
    }
    cur_player = !cur_player;
  }

  cout << dp.at(0, N - 1, 0) << endl;
  return 0;
}
