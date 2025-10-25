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

// use sort & binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    unordered_map<long long, int> count;
    long minimum = nums[0], maximum = nums[0];
    for (int& num : nums) {
      count[num]++;
      minimum = min((long)num, minimum);
      maximum = max((long)num, maximum);
    }

    function<int(long)> calc = [&](long mid) {
      int left = max(minimum, mid - k);
      int right = min(maximum, mid + k);

      int rangeCount = upper_bound(nums.begin(), nums.end(), right) -
                       lower_bound(nums.begin(), nums.end(), left);
      return min(count[mid] + numOperations, rangeCount);
    };

    int answer = 0;

    for (int& num : nums) {
      long target = num;
      answer = max(answer, calc(target + k));
      answer = max(answer, calc(target));
    }

    return answer;
  }
};

// use sort & two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    unordered_map<int, int> count;

    for (int i = 0; i < size; i++) {
      count[nums[i]]++;
    }

    int answer = 0;

    // target val is in nums
    for (int i = 0, left = 0, right = 0; i < size; i++) {
      while (left < size && nums[i] - k > nums[left]) {
        left++;
      }
      while (right < size && nums[right] <= nums[i] + k) {
        right++;
      }

      answer = max(answer, min(right - left, numOperations + count[nums[i]]));
    }

    // target val is not in nums
    for (int left = 0, right = 0; right < size; right++) {
      while (nums[right] - nums[left] > (2 * k)) {
        left++;
      }

      answer = max(answer, min(right - left + 1, numOperations));
    }

    return answer;
  }
};