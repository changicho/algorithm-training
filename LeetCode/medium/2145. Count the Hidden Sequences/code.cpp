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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long cur = 0;
    long long maximum = 0, minimum = 0;
    for (int& diff : differences) {
      cur += diff;
      maximum = max(cur, maximum);
      minimum = min(cur, minimum);
    }

    long long diff = maximum - minimum;
    long long diffRange = (long long)upper - lower;

    return max(diffRange - diff + 1, 0LL);
  }
};