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

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int ones = accumulate(nums.begin(), nums.end(), 0);

    int size = nums.size();

    int curOne = 0;
    for (int i = 0; i < ones; i++) {
      curOne += nums[i];
    }

    int answer = INT_MAX;
    for (int left = 0; left < size; left++) {
      int right = (left + ones) % size;

      answer = min(answer, ones - curOne);
      curOne -= nums[left];
      curOne += nums[right];
    }

    return answer;
  }
};