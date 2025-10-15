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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int size = nums.size();

    int count1 = 1, count2 = 1;
    if (count1 >= k && count2 >= k) return true;
    for (int i = 1, j = k + 1; j < size; i++, j++) {
      if (nums[i - 1] >= nums[i]) {
        count1 = 0;
      }

      if (nums[j - 1] >= nums[j]) {
        count2 = 0;
      }

      count1++;
      count2++;

      if (count1 >= k && count2 >= k) return true;
    }

    return false;
  }
};

// use stack
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int size = nums.size();

    vector<int> stk1, stk2;
    for (int i = 0, j = k; j < size; i++, j++) {
      if (!stk1.empty() && stk1.back() >= nums[i]) {
        stk1.clear();
      }

      if (!stk2.empty() && stk2.back() >= nums[j]) {
        stk2.clear();
      }

      stk1.push_back(nums[i]);
      stk2.push_back(nums[j]);

      if (stk1.size() >= k && stk2.size() >= k) return true;
    }

    return false;
  }
};

// use brute force
// time : O(N * K)
// space : O(1)
class Solution {
 public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int size = nums.size();

    for (int i = 0; i <= size - 2 * k; i++) {
      bool isFine = true;

      for (int j = i; j < i + k - 1; j++) {
        if (nums[j] >= nums[j + 1]) {
          isFine = false;
          break;
        }
      }
      for (int j = i + k; j < i + 2 * k - 1; j++) {
        if (nums[j] >= nums[j + 1]) {
          isFine = false;
          break;
        }
      }

      if (isFine) return true;
    }

    return false;
  }
};