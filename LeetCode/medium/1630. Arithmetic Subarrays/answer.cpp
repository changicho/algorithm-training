#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(M * N * log_2(N))
// space : O(N)
class Solution {
 private:
  bool isArithmetic(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) return false;
    sort(nums.begin(), nums.end());

    int diff = nums[1] - nums[0];

    for (int i = 1; i < size; i++) {
      int curDiff = nums[i] - nums[i - 1];

      if (diff != curDiff) return false;
    }
    return true;
  }

 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    int qSize = l.size();

    vector<bool> answer;

    for (int i = 0; i < qSize; i++) {
      int left = l[i], right = r[i];

      vector<int> cur(nums.begin() + left, nums.begin() + right + 1);

      bool ret = isArithmetic(cur);
      answer.push_back(ret);
    }

    return answer;
  }
};