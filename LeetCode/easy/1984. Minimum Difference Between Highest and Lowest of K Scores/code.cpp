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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = INT_MAX;

    for (int i = 0; i <= size - k; i++) {
      int left = i, right = i + k - 1;

      int diff = nums[right] - nums[left];

      answer = min(answer, diff);
    }
    return answer;
  }
};