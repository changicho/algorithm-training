#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int size = nums.size();
    unordered_map<int, int> prefixCounts;
    prefixCounts[0]++;

    int count = 0;
    long long answer = 0;
    for (int& num : nums) {
      if (num % modulo == k) {
        count++;
      }
      count %= modulo;

      int target = (count - k + modulo) % modulo;
      if (prefixCounts.count(target) > 0) {
        answer += prefixCounts[target];
      }
      prefixCounts[count]++;
    }
    return answer;
  }
};