#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use queue
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    queue<int> q;

    for (int& num : nums) {
      q.push(num);
    }
    while (q.size() > 1) {
      int size = q.size();

      for (int i = 0; i < size / 2; i++) {
        int first = q.front();
        q.pop();
        int second = q.front();
        q.pop();

        if (i % 2 == 0) {
          q.push(min(first, second));
        } else {
          q.push(max(first, second));
        }
      }
    }
    return q.front();
  }
};

// use O(1) space brute force
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    for (int size = nums.size(); size > 1; size = (size + 1) / 2) {
      for (int i = 0; i < size / 2; i++) {
        if (i % 2 == 0) {
          nums[i] = min(nums[2 * i], nums[2 * i + 1]);
        } else {
          nums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
      }
    }
    return nums.front();
  }
};