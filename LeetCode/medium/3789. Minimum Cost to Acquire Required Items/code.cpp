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

// use greedy
// time : O(1)
// space : O(1)
class Solution {
 public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                        int need2) {
    long long answer = 0;

    int duplicated = min(need1, need2);
    if (costBoth <= cost1 + cost2) {
      answer += (long long)costBoth * duplicated;
    } else {
      answer += (long long)(cost1 + cost2) * duplicated;
    }
    need1 -= duplicated;
    need2 -= duplicated;

    if (need1 > 0) {
      answer += (long long)need1 * min(costBoth, cost1);
    }
    if (need2 > 0) {
      answer += (long long)need2 * min(costBoth, cost2);
    }
    return answer;
  }
};