#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(void) {
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;

  unordered_map<char, int>map;
  
  for (auto c: s) {
    map[c]++;
  }
  
  ull odd_count = 0;
  char odd_char = 0;
  const ull odd_limit = s.length() & 1;
  
  string first_half = "", second_half = "";
  
  for (auto pair: map) {
    if (pair.second & 1) {
      odd_count++;
      if (odd_count > odd_limit) {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      odd_char = pair.first;
    }
    
    string aux(pair.second >> 1, pair.first);
    first_half = first_half + aux;
    second_half = aux + second_half;
  }
  
  cout << first_half;
  if (odd_char) cout << odd_char;
  cout << second_half << endl;

  return 0;
}
