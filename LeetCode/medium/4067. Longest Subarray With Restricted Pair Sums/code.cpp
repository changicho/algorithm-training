#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// sliding window
// time : O(NM)
// space : O(M)
class Solution {
 public:
  int maxSubarray(vector<int>& nums) {
    int count[501] = {
        0,
    };

    function<bool(int)> check = [&](int target) {
      for (int num = 0; num <= 500; num++) {
        if (count[num] == 0) continue;

        if (target == (num * 2)) {
          if (count[num] >= 2) {
            return false;
          }
        } else {
          if (target - num >= 0 && count[target - num] >= 1) {
            return false;
          }
        }
        if (num + target <= 500 && count[num + target] >= 1) {
          return false;
        }
      }
      return true;
    };

    int size = nums.size();

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      while (left < right && !check(nums[right])) {
        count[nums[left]]--;
        left++;
      }

      count[nums[right]]++;

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};