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
// space : O(N)
class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int size = nums.size();
    bool used[10001] = {
        false,
    };

    int answer = 0;
    int sum = 0;

    for (int left = 0, right = 0; right < size; right++) {
      while (left < right && used[nums[right]]) {
        used[nums[left]] = false;
        sum -= nums[left];
        left++;
      }

      sum += nums[right];
      used[nums[right]] = true;

      answer = max(answer, sum);
    }
    return answer;
  }
};