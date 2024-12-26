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
 private:
  bool isValid(map<int, int>& count, int val) {
    if (count.lower_bound(val - 2) != count.begin()) return false;
    if (count.lower_bound(val + 2 + 1) != count.end()) return false;
    return true;
  }

 public:
  long long continuousSubarrays(vector<int>& nums) {
    int size = nums.size();

    long long answer = 0;

    map<int, int> count;

    for (int left = 0, right = 0; right < size; right++) {
      int cur = nums[right];

      while (left < right && !isValid(count, cur)) {
        count[nums[left]]--;

        if (count[nums[left]] == 0) {
          count.erase(nums[left]);
        }
        left++;
      }

      count[cur]++;
      int length = right - left + 1;

      answer += length;
    }
    return answer;
  }
};