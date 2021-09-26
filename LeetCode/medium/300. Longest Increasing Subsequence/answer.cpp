#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use LIS

class Solution {
 private:
  struct LIS {
    int index, value;
  };

 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<LIS> lis;
    vector<int> cache(size, 0);
    int index = 0;

    cache[index] = nums[0];
    lis.push_back({0, nums[0]});

    for (int i = 1; i < size; i++) {
      if (cache[index] < nums[i]) {
        index++;
        cache[index] = nums[i];

        lis.push_back({index, nums[i]});
      } else {
        int target =
            lower_bound(cache.begin(), cache.begin() + index, nums[i]) -
            cache.begin();

        cache[target] = nums[i];
        lis.push_back({target, nums[i]});
      }
    }

    return index + 1;
  }
};

// use LIS

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> lis;

    for (int i = 0; i < size; i++) {
      int target = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

      if (target == lis.size()) {
        lis.push_back(nums[i]);
      } else {
        lis[target] = nums[i];
      }
    }

    return lis.size();
  }
};

// use dynamic programming

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();

    vector<int> dp(size, 1);
    int answer = 1;

    for (int right = 1; right < size; right++) {
      for (int left = 0; left < right; left++) {
        if (nums[left] < nums[right]) {
          dp[right] = max(dp[left] + 1, dp[right]);
        }
      }

      answer = max(answer, dp[right]);
    }

    return answer;
  }
};