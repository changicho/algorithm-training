#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use monotonic deque
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int size = nums.size();
    deque<int> maxDq, minDq;

    int answer = 0;
    for (int l = 0, r = 0; r < size; r++) {
      while (!maxDq.empty() && maxDq.back() < nums[r]) {
        maxDq.pop_back();
      }
      maxDq.push_back(nums[r]);

      while (!minDq.empty() && minDq.back() > nums[r]) {
        minDq.pop_back();
      }
      minDq.push_back(nums[r]);

      while (l < r && maxDq.front() - minDq.front() > limit) {
        if (maxDq.front() == nums[l]) {
          maxDq.pop_front();
        }
        if (minDq.front() == nums[l]) {
          minDq.pop_front();
        }
        l++;
      }

      answer = max(answer, r - l + 1);
    }

    return answer;
  }
};