#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// union find
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                    vector<vector<int>>& queries) {
    vector<int> parents(n);
    int color = 1;
    parents[0] = 1;
    for (int i = 0; i < n - 1; i++) {
      if (abs(nums[i] - nums[i + 1]) > maxDiff) {
        color++;
      }

      parents[i + 1] = color;
    }

    vector<bool> answer;
    for (vector<int>& q : queries) {
      bool cur = parents[q[0]] == parents[q[1]];

      answer.push_back(cur);
    }
    return answer;
  }
};