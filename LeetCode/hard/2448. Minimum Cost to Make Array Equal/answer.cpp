#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use ternary search
// time : O(N * log_3(M))
// space : O(1)
class Solution {
 private:
  long long getCostSum(vector<int>& nums, vector<int>& cost, int target) {
    int size = nums.size();

    long long costSum = 0;
    for (int i = 0; i < size; i++) {
      costSum += abs(target - nums[i]) * (long long)cost[i];
    }
    return costSum;
  }

 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    long long answer = LLONG_MAX;

    int left = nums.front(), right = nums.front();
    for (int& num : nums) {
      left = min(left, num);
      right = max(right, num);
    }

    while (left + 3 <= right) {
      int leftPart = (2 * left + right) / 3;
      int rightPart = (left + 2 * right) / 3;

      long long costL = getCostSum(nums, cost, leftPart);
      long long costR = getCostSum(nums, cost, rightPart);

      if (costL < costR) {
        right = rightPart;
      } else {
        left = leftPart;
      }
    }

    for (int i = left; i <= right; i++) {
      answer = min(answer, getCostSum(nums, cost, i));
    }

    return answer;
  }
};

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  long long getCostSum(vector<int>& nums, vector<int>& cost, int target) {
    int size = nums.size();

    long long costSum = 0;
    for (int i = 0; i < size; i++) {
      costSum += abs(target - nums[i]) * (long long)cost[i];
    }
    return costSum;
  }

 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int left = nums.front(), right = nums.front();
    for (int& num : nums) {
      left = min(left, num);
      right = max(right, num);
    }
    right++;

    long long answer = getCostSum(nums, cost, left);

    while (left < right) {
      int mid = left + (right - left) / 2;
      long long costMidL = getCostSum(nums, cost, mid),
                costMidR = getCostSum(nums, cost, mid + 1);
      answer = min(costMidL, costMidR);

      if (costMidL < costMidR) {
        // pick left part
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    return answer;
  }
};