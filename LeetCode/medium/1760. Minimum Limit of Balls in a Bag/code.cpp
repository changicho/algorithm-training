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

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  bool calc(vector<int> &nums, int limit, int oper) {
    int count = 0;
    for (int &num : nums) {
      int curCount = num / limit + (num % limit > 0) - 1;
      count += curCount;

      if (count > oper) return false;
    }
    return true;
  }

 public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;

    int answer = INT_MAX;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (calc(nums, mid, maxOperations)) {
        // pick left part
        right = mid;
        answer = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }
    return answer;
  }
};