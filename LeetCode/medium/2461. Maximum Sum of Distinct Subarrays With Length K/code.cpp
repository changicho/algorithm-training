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

// use sliding window
// time : O(N)
// space : O(K)
class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int size = nums.size();

    unordered_map<int, int> count;
    int duplicateCount = 0;
    long long sum = 0;
    long long answer = 0;
    for (int right = 0; right < size; right++) {
      int left = right - k;
      count[nums[right]]++;

      if (count[nums[right]] == 2) {
        duplicateCount++;
      }
      sum += nums[right];
      if (left >= 0) {
        count[nums[left]]--;
        if (count[nums[left]] == 1) {
          duplicateCount--;
        } else if (count[nums[left]] == 0) {
          count.erase(nums[left]);
        }
        sum -= nums[left];
      }

      if (duplicateCount == 0 && (right + 1 >= k)) {
        answer = max(answer, sum);
      }
    }
    return answer;
  }
};