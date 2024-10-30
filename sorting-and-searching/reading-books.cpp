#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(void) {
  int n;
  cin >> n;
  
  vector<int>books(n);
  for (auto &t : books) cin >> t;
  
  sort(books.begin(), books.end());
  
  ull sum = accumulate(books.begin(), books.end(), 0ULL);
  ull longest_book = *books.rbegin(); 
  
  // Case 1: The maximum reading time book is greater or equal than the sum of the reading time of the other books
  // In this case, it's trivial to notice that the total time required will be twice the time to read the longest book
  if (longest_book >= sum - longest_book) cout << 2 * longest_book << endl;
  // Case 2: The maximum reading time book is smaller than the sum of the reading time of the other books
  // In this case, let's use the following approach:
  //    Ask Kotivalo to start reading the book with the maximum reading time and ask Justiina to start 
  //    reading from the book with the minimum reading time. After Kotivalo finishes reading his book,
  //    he can also start from the book with the minimum reading time.
  //
  // Following this approach, when Kotivalo finishes reading his first book, Justiina,
  // unlike the first case, has not yet finished reading all the books. So, as Kotivalo
  // already read the maximum reading time book, it is easy (or not) to notice that, 
  // following the above approach, no other reading conflicts will occur. So the total
  // reading time is simply the sum of all books' reading times.
  else cout << sum << endl;

  return 0;
}
