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

// use sort & greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxDistinctElements(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    int answer = 1;
    nums[0] -= k;
    for (int i = 1; i < size; i++) {
      nums[i] = min(max(nums[i] - k, nums[i - 1] + 1), nums[i] + k);

      if (nums[i] > nums[i - 1]) {
        answer++;
      }
    }
    return answer;
  }
};

// use sort & greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 0, prev = INT_MIN;

    for (int& num : nums) {
      int cur = min(max(num - k, prev + 1), num + k);

      if (cur > prev) {
        count++;
        prev = cur;
      }
    }
    return count;
  }
};