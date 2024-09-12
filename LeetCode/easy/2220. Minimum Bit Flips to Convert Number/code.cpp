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

// use bit operation
// time : O(1)
// space : O(1)
class Solution {
 public:
  int minBitFlips(int start, int goal) {
    int bit = start ^ goal;

    return __builtin_popcount(bit);
  }
};