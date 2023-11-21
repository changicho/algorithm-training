#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort & queue
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    int diffSum = 0;
    queue<int> q;

    int answer = 1;
    q.push(nums[0]);
    for (int i = 1; i < size; i++) {
      int diff = nums[i] - nums[i - 1];

      int curCost = diffSum + q.size() * diff;

      while (curCost > k && q.size() > 0) {
        diffSum -= nums[i - 1] - q.front();
        q.pop();
        curCost = diffSum + q.size() * diff;
      }

      diffSum += q.size() * diff;
      q.push(nums[i]);
      answer = max(answer, (int)q.size());
    }

    return answer;
  }
};

// use sort & sliding window
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    long diffSum = 0;
    int left = 0;

    int answer = 1;
    for (int right = 1; right < size; right++) {
      int diff = nums[right] - nums[right - 1];

      long curCost = diffSum + (long)(right - left) * diff;

      while (curCost > k && left < right) {
        diffSum -= nums[right - 1] - nums[left];
        left++;
        curCost = diffSum + (long)(right - left) * diff;
      }

      diffSum += (right - left) * diff;
      answer = max(answer, (right - left) + 1);
    }

    return answer;
  }
};