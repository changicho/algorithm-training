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
// time : O(N^2 * log_2(N))
// space : O(N^2)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> sums;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        sum %= MOD;

        sums.push_back(sum);
      }
    }

    sort(sums.begin(), sums.end());

    int answer = 0;
    for (int i = left - 1; i < right; i++) {
      answer += sums[i];
      answer %= MOD;
    }
    return answer;
  }
};

// use binary search
// time : O(N * log_2(SUM))
// space : O(1)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  pair<int, long long> countAndSum(vector<int>& nums, int targetSum) {
    int size = nums.size();

    int count = 0;
    long long curSum = 0, totalSum = 0, windowSum = 0;

    for (int left = 0, right = 0; right < size; right++) {
      curSum += nums[right];
      windowSum += nums[right] * (right - left + 1);

      while (curSum > targetSum) {
        windowSum -= curSum;
        curSum -= nums[left];

        left++;
      }

      count += right - left + 1;
      totalSum += windowSum;
    }
    return {count, totalSum};
  }

  long long sumOfFirstK(vector<int>& nums, int k) {
    int left = 0, right = accumulate(nums.begin(), nums.end(), 0);

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (countAndSum(nums, mid).first >= k) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    auto [count, sum] = countAndSum(nums, left);

    return sum - left * (count - k);
  }

 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    long result =
        (sumOfFirstK(nums, right) - sumOfFirstK(nums, left - 1)) % MOD;

    return (result + MOD) % MOD;
  }
};