#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();
    int last = size - 1;
    if (size <= 4) return 0;

    sort(nums.begin(), nums.end());

    int first = nums[last] - nums[3], second = nums[last - 1] - nums[2],
        third = nums[last - 2] - nums[1], fourth = nums[last - 3] - nums[0];

    int answer = min({first, second, third, fourth});
    return answer;
  }
};

// use sort & sliding window

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int size = nums.size();
    int last = size - 1;
    if (size <= 4) return 0;

    sort(nums.begin(), nums.end());

    int answer = nums.back() - nums.front();
    deque<int> dq;
    for (int i = 0; i < size; i++) {
      dq.push_back(nums[i]);

      if (dq.size() == size - 3) {
        int diff = dq.back() - dq.front();
        answer = min(answer, diff);
        dq.pop_front();
      }
    }

    return answer;
  }
};