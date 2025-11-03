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

// use sort & dynamic programming
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maximumTotalDamage(vector<int>& power) {
    int size = power.size();

    sort(power.begin(), power.end());

    // skip -2, -1
    vector<long long> maximums(size, 0);

    maximums[0] = power[0];

    long long before = power[0];
    for (int i = 1, j = 0; i < size; i++) {
      while (j + 1 < i && power[j + 1] + 2 < power[i]) {
        j++;
      }

      long long cur = power[i];

      if (power[i] == power[i - 1] || power[i] - 2 > power[i - 1]) {
        cur = max(cur, before + power[i]);
      }

      if (power[j] + 2 < power[i]) {
        cur = max(cur, maximums[j] + power[i]);
      }

      maximums[i] = max(maximums[i - 1], cur);
      before = cur;
    }

    return maximums.back();
  }
};