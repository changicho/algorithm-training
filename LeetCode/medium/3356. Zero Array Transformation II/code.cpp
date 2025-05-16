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

// use sweeping
// time : O(N + M)
// space : O(N)
class Solution {
 public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int size = nums.size(), qSize = queries.size();

    int answer = 0;

    int diff = 0;
    vector<int> diffs(size + 1);
    for (int i = 0; i < size; i++) {
      while (diff + diffs[i] < nums[i]) {
        if (answer >= qSize) {
          return -1;
        }

        vector<int>& query = queries[answer];
        answer++;

        int left = query[0], right = query[1], val = query[2];

        if (right >= i) {
          diffs[max(left, i)] += val;
          diffs[right + 1] -= val;
        }
      }

      diff += diffs[i];
    }
    return answer;
  }
};