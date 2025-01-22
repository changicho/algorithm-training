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

// use prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    int cols = grid[0].size();

    long long sum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
    long long sum2 = accumulate(grid[1].begin(), grid[1].end(), 0LL);

    long long cur1 = 0;
    long long cur2 = 0;

    long long answer = LONG_LONG_MAX;

    for (int x = 0; x < cols; x++) {
      cur1 += grid[0][x];
      long long cur = cur1 + sum2 - cur2;

      long long choose2 = max(sum1 - cur1, cur2);
      answer = min(answer, choose2);

      cur2 += grid[1][x];
    }
    return answer;
  }
};