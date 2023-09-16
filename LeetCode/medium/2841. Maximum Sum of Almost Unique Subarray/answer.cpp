#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(K)
class Solution {
 public:
  long long maxSum(vector<int>& nums, int m, int k) {
    int size = nums.size();

    long long answer = 0;
    long long sum = 0;
    unordered_map<int, int> counts;
    for (int i = 0; i < k; i++) {
      int num = nums[i];
      sum += num;
      counts[num]++;
    }

    // update init
    if (counts.size() >= m) {
      answer = max(answer, sum);
    }

    for (int right = k; right < size; right++) {
      int left = right - k;

      counts[nums[left]]--;
      sum -= nums[left];
      if (counts[nums[left]] == 0) {
        counts.erase(nums[left]);
      }

      sum += nums[right];
      counts[nums[right]]++;

      if (counts.size() >= m) {
        answer = max(answer, sum);
      }
    }
    return answer;
  }
};