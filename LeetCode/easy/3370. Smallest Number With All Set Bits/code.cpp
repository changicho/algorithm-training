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

// use simulation
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int smallestNumber(int n) {
    int cur = 1;
    while (cur < n) {
      cur = (cur << 1) + 1;
    }

    return cur;
  }
};