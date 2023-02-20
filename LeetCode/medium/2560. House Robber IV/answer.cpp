#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use binary search
// time : O(N) = O(N * log_2(1e9))
// space : O(1)
class Solution {
 private:
  int getMaximumChoosableHouse(vector<int>& nums, int cost) {
    int size = nums.size();
    int count = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] <= cost) {
        count++;
        i++;
      }
    }

    return count;
  }

 public:
  int minCapability(vector<int>& nums, int k) {
    int size = nums.size();

    int answer = INT_MAX;
    int left = 0, right = 1e9 + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (getMaximumChoosableHouse(nums, mid) >= k) {
        // pick left;
        answer = min(answer, mid);
        right = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }
    return answer;
  }
};