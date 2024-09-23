#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

vector<string> solve(string s) {
  size_t length = s.length();
  sort(s.begin(), s.end());
  
  vector<string> permutations;

  while (true) {
    permutations.push_back(s);

    int i; // Largest index such that cᵢ < cᵢ₊₁ (cᵢ₊₁ > cᵢ₊₂ > . . . > cₙ)
    for (i = length - 2; i >= 0; i--) {
      if (s[i] < s[i + 1]) break;
    }
    
    // All permutations generated
    if (i < 0) break;
    
    int j; // Largest index such that cᵢ < cⱼ (j >= i + 1 since cᵢ < cᵢ₊₁)
    for (j = length - 1; j > i + 1; j--) {
      if (s[j] > s[i]) break;
    }
    
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
  }

  return permutations;
}

/*
// Using lib
vector<string> solve(string s) {
  sort(s.begin(), s.end());
  vector<string> permutations;
  
  do {
    permutations.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  
  return permutations;
}
*/

int main(void) {
  ios::sync_with_stdio(false);

  string str;
  cin >> str;
  
  vector<string> permutations = solve(str);
  cout << permutations.size() << endl;

  for (auto s: permutations) {
    cout << s << endl;
  }

  return 0;
}
