#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force (TLE)
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int size = nums.size();

    int maximum = INT_MIN;
    for (int start = 0; start < size; start++) {
      int cur = 0;
      for (int i = 0; i < size; i++) {
        cur += i * nums[(start + i) % size];
      }

      maximum = max(maximum, cur);
    }

    return maximum;
  }
};

// use dp with math
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int size = nums.size();

    vector<int> dp(size, 0);
    int sum = 0;

    for (int i = 0; i < size; i++) {
      sum += nums[i];
      dp[0] += i * nums[i];
    }

    int maximum = dp[0];
    for (int i = 1; i < size; i++) {
      dp[i] = dp[i - 1] + sum - size * nums[size - i];
      maximum = max(maximum, dp[i]);
    }

    return maximum;
  }
};

// use optimized dp with math
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int size = nums.size();

    int cur = 0;
    int sum = 0;

    for (int i = 0; i < size; i++) {
      sum += nums[i];
      cur += i * nums[i];
    }

    int maximum = cur;
    for (int i = 1; i < size; i++) {
      cur = cur + sum - size * nums[size - i];
      maximum = max(maximum, cur);
    }

    return maximum;
  }
};