#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use custom sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  int getScore(int num) {
    int count = 0;
    while (num > 0) {
      count += num % 2;
      num /= 2;
    }
    return count;
  }

 public:
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [&](int &a, int &b) {
      int retA = getScore(a), retB = getScore(b);
      if (retA == retB) return a < b;
      return retA < retB;
    });

    return arr;
  }
};

// use custom sort (built in)
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](int &a, int &b) {
      int retA = __builtin_popcount(a), retB = __builtin_popcount(b);
      if (retA == retB) return a < b;
      return retA < retB;
    });

    return arr;
  }
};