#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// using sort

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int answer = nums.front() + nums.back();

    int center = size / 2;
    for (int i = 0; i < size / 2; i++) {
      // current pair is {nums[center - 1 - i], nums[cetner + i]}
      answer = max(nums[center - 1 - i] + nums[center + i], answer);
    }

    return answer;
  }
};