#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    for (int& num : nums) {
      num = num * num;
    }

    sort(nums.begin(), nums.end());
    return nums;
  }
};

// use two pointer with dq
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    deque<int> dq;

    int left = 0, right = nums.size() - 1;

    while (left < right) {
      if (abs(nums[left]) > abs(nums[right])) {
        dq.push_front(nums[left] * nums[left]);
        left += 1;
      } else {
        dq.push_front(nums[right] * nums[right]);
        right -= 1;
      }
    }

    dq.push_front(nums[left] * nums[left]);

    vector<int> array;
    for (int num : dq) {
      array.emplace_back(num);
    }
    return array;
  }
};

// use two pointer
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> answer;

    int left = 0, right = nums.size() - 1;

    while (left < right) {
      if (abs(nums[left]) > abs(nums[right])) {
        answer.push_back(nums[left] * nums[left]);
        left += 1;
      } else {
        answer.push_back(nums[right] * nums[right]);
        right -= 1;
      }
    }

    answer.push_back(nums[left] * nums[left]);
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
