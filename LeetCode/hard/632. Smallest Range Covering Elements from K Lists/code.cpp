#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use set & binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    set<int> s;
    for (vector<int> &arr : nums) {
      for (int &num : arr) {
        s.insert(num);
      }
    }

    vector<int> answer = {0, INT_MAX};

    for (int left : s) {
      int right = left;

      for (vector<int> &arr : nums) {
        int index = lower_bound(arr.begin(), arr.end(), left) - arr.begin();

        if (index == arr.size()) {
          right = INT_MAX;
          continue;
        }

        int target = arr[index];
        right = max(right, target);
      }

      int range = right - left;

      if (range < (answer[1] - answer[0])) {
        answer = {left, right};
      }
    }
    return answer;
  }
};

// use heap
// time : O(N * log_2(K))
// space : O(K)
class Solution {
 private:
  struct Data {
    int val, row, col;

    const bool operator<(const Data &d) const { return val > d.val; }
  };

 public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int size = nums.size();

    priority_queue<Data> pq;
    int curMax = INT_MIN;
    vector<int> answer = {0, INT_MAX};

    for (int row = 0; row < size; row++) {
      pq.push({nums[row][0], row, 0});
      curMax = max(curMax, nums[row][0]);
    }

    while (pq.size() == size) {
      auto [val, row, col] = pq.top();
      pq.pop();

      if (curMax - val < (answer[1] - answer[0])) {
        answer = {val, curMax};
      }

      if (col + 1 < nums[row].size()) {
        int next = nums[row][col + 1];

        pq.push({next, row, col + 1});
        curMax = max(curMax, next);
      }
    }

    return answer;
  }
};