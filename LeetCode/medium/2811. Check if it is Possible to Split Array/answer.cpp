#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (bottom up)
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  struct Status {
    int left, right, sum;
  };

 public:
  bool canSplitArray(vector<int>& nums, int m) {
    int size = nums.size();
    if (size <= 2) return true;

    int left = 0, right = size - 1;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    bool visited[101][101] = {
        0,
    };

    if (sum < m) return false;

    queue<Status> q;
    q.push({left, right, sum});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (cur.right - cur.left <= 1) return true;
      if (visited[cur.left][cur.right]) continue;
      visited[cur.left][cur.right] = true;

      // check pick left
      int nextSum = cur.sum;
      if ((nextSum - nums[cur.left]) >= m) {
        q.push({cur.left + 1, cur.right, nextSum - nums[cur.left]});
      }
      if ((nextSum - nums[cur.right]) >= m) {
        q.push({cur.left, cur.right - 1, nextSum - nums[cur.right]});
      }
    }

    return false;
  }
};

// use dynamic programming (top down)
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  bool answer = false;
  vector<int> nums;

  bool visited[101][101] = {
      false,
  };

  void recursive(int left, int right, int sum, int m) {
    if (visited[left][right]) return;
    visited[left][right] = true;

    if (right - left <= 1) answer = true;

    if (sum - nums[left] >= m) {
      recursive(left + 1, right, sum - nums[left], m);
    }
    if (sum - nums[right] >= m) {
      recursive(left, right - 1, sum - nums[right], m);
    }
  }

 public:
  bool canSplitArray(vector<int>& nums, int m) {
    int size = nums.size();
    if (size <= 2) return true;
    this->nums = nums;

    int left = 0, right = size - 1;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    recursive(left, right, sum, m);

    return answer;
  }
};