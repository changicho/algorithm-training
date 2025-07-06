#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use iteration
// time : O(log_2(K))
// space : O(1)
class Solution {
 public:
  char kthCharacter(long long k, vector<int>& operations) {
    int diff = 0;

    while (k > 1) {
      int step = log2(k);

      long long half = 1LL << step;
      if (half == k) {
        half /= 2;
        step--;
      }

      k -= half;
      if (operations[step]) {
        diff++;
      }
    }

    return 'a' + (diff % 26);
  }
};