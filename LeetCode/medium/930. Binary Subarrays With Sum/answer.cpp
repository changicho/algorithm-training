#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use prefix sum & hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> counts;

    int answer = 0;
    counts[0] = 1;
    int sum = 0;
    for (int& num : nums) {
      sum += num;

      answer += counts[sum - goal];

      counts[sum]++;
    }
    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int size = nums.size();

    int answer = 0;
    int sum = 0;
    int prefixZeros = 0;

    for (int left = 0, right = 0; right < size; right++) {
      sum += nums[right];

      while (left < right && (nums[left] == 0 || sum > goal)) {
        if (nums[left] == 1) {
          prefixZeros = 0;
        } else {
          prefixZeros++;
        }

        sum -= nums[left];
        left++;
      }

      if (sum == goal) {
        answer += 1 + prefixZeros;
      }
    }

    return answer;
  }
};