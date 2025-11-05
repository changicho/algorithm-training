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
  int maxIncreasingSubarrays(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    int before = 0;
    int count = 1;
    for (int i = 1; i < size; i++) {
      if (nums[i - 1] >= nums[i]) {
        before = count;
        count = 0;
      }

      count++;

      answer = max({answer, min(before, count), count / 2});
    }

    return answer;
  }
};

// use binary search
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  bool check(vector<int>& nums, int k) {
    int size = nums.size();

    int count1 = 0, count2 = 0;
    for (int i = 0, j = k; j < size; i++, j++) {
      if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
        count1 = 0;
      }

      if (j >= 0 && nums[j - 1] >= nums[j]) {
        count2 = 0;
      }

      count1++;
      count2++;

      if (count1 >= k && count2 >= k) return true;
    }

    return false;
  }

 public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    int size = nums.size();

    int left = 1, right = size;
    int answer = 0;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (check(nums, mid)) {
        answer = max(answer, mid);
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return answer;
  }
};