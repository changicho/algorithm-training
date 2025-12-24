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

// use mod
// time : O(K)
// space : O(1)
class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    int cur = 0;
    for (int i = 1; i <= k; i++) {
      cur = (cur * 10 + 1) % k;
      if (cur == 0) return i;
    }
    return -1;
  }
};