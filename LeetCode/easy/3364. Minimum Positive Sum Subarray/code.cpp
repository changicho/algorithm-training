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

// brute force
// time : O(NR)
// space : O(1)
class Solution {
 public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int size = nums.size();
    int answer = INT_MAX;

    for (int i = 0; i < size; i++) {
      int cur = 0;
      for (int j = i; j < size; j++) {
        cur += nums[j];

        int len = j - i + 1;
        if (r < len) break;
        if (l <= len && cur > 0) {
          answer = min(answer, cur);
        }
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};