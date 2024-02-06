#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> answer;
    for (int i = 0; i < size; i += 3) {
      vector<int> cur = {nums[i], nums[i + 1], nums[i + 2]};

      if (cur.back() - cur.front() > k) return {};
      answer.push_back(cur);
    }
    return answer;
  }
};