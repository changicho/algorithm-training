#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use back tracking
// time : O(2^N * N^2)
// space : O(2^N * N)
class Solution {
 private:
  set<vector<int>> answer;

  void recursive(int index, vector<int> &nums, vector<int> &cur) {
    int size = nums.size();

    if (size == index) {
      if (cur.size() >= 2) {
        answer.insert(cur);
      }
      return;
    }

    if (cur.empty() || cur.back() <= nums[index]) {
      cur.push_back(nums[index]);
      recursive(index + 1, nums, cur);
      cur.pop_back();
    }

    recursive(index + 1, nums, cur);
  }

 public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> cur;
    recursive(0, nums, cur);

    vector<vector<int>> ret;
    for (auto &ans : answer) {
      ret.push_back(ans);
    }
    return ret;
  }
};
