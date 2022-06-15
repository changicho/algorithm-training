#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sliding window (queue)
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    int size = nums.size();

    long long ret = 0;
    queue<int> q;

    long long sum = 0;
    for (int i = 0; i < size; i++) {
      q.push(nums[i]);
      sum += nums[i];

      while (sum * q.size() >= k && !q.empty()) {
        sum -= q.front();
        q.pop();
      }

      ret += q.size();
    }

    return ret;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    int size = nums.size();

    long long ret = 0;
    long long sum = 0;
    for (int left = 0, right = 0; right < size; right++) {
      sum += nums[right];

      while (left <= right && sum * (right - left + 1) >= k) {
        sum -= nums[left];
        left++;
      }

      ret += (right - left + 1);
    }

    return ret;
  }
};