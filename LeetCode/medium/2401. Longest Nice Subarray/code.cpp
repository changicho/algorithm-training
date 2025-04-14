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
  int longestNiceSubarray(vector<int>& nums) {
    int size = nums.size();

    int bit = 0;
    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      while ((bit & nums[right]) > 0) {
        bit ^= nums[left];
        left++;
      }

      bit |= nums[right];

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};