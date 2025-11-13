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

// use greedy
// time : O(N^2 * log_2(M))
// space : O(1)
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();

    int oneCount = 0;
    int allGcd = nums[0];

    for (int& num : nums) {
      if (num == 1) oneCount++;

      allGcd = gcd(num, allGcd);
    }

    if (allGcd != 1) return -1;
    if (oneCount > 0) {
      return size - oneCount;
    }

    int makeOneDiff = size;
    for (int left = 0; left < size; left++) {
      int val = 0;
      for (int right = left; right < size; right++) {
        val = gcd(val, nums[right]);
        if (val == 1) {
          makeOneDiff = min(makeOneDiff, right - left + 1);
          break;
        }
      }
    }

    return size - 1 + makeOneDiff - 1;
  }
};