#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();
    int last = size - 1;
    if (size <= 4) return 0;

    sort(nums.begin(), nums.end());

    int first = nums[last] - nums[3], second = nums[last - 1] - nums[2],
        third = nums[last - 2] - nums[1], fourth = nums[last - 3] - nums[0];

    int answer = min({first, second, third, fourth});
    return answer;
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    if (size <= 4) {
      return 0;
    }

    int answer = INT_MAX;
    for (int i = 0; i <= 3; i++) {
      int diff = nums[size - 1 - (3 - i)] - nums[i];

      answer = min(answer, diff);
    }
    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();

    int mins[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    int maxs[4] = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

    if (size <= 4) {
      return 0;
    }

    for (int& num : nums) {
      for (int i = 0; i < 4; i++) {
        if (mins[i] >= num) {
          for (int j = 2; j >= i; j--) {
            mins[j + 1] = mins[j];
          }
          mins[i] = num;
          break;
        }
      }
      for (int i = 0; i < 4; i++) {
        if (maxs[i] <= num) {
          for (int j = 2; j >= i; j--) {
            maxs[j + 1] = maxs[j];
          }
          maxs[i] = num;
          break;
        }
      }
    }

    int answer = INT_MAX;
    for (int i = 0; i < 4; i++) {
      int cur = maxs[i] - mins[3 - i];
      answer = min(answer, cur);
    }
    return answer;
  }
};

// use sort & sliding window
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();
    int last = size - 1;
    if (size <= 4) return 0;

    sort(nums.begin(), nums.end());

    int answer = nums.back() - nums.front();
    deque<int> dq;
    for (int i = 0; i < size; i++) {
      dq.push_back(nums[i]);

      if (dq.size() == size - 3) {
        int diff = dq.back() - dq.front();
        answer = min(answer, diff);
        dq.pop_front();
      }
    }

    return answer;
  }
};