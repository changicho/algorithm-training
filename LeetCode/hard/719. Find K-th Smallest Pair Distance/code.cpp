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

// use binary search with sliding window
// time : O(N * log_2(N * M))
// space : O(N)
class Solution {
 private:
  // sliding window
  int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
    int size = nums.size();
    int count = 0;

    for (int left = 0, right = 0; right < size; right++) {
      while (nums[right] - nums[left] > maxDistance) {
        left++;
      }

      count += right - left;
    }
    return count;
  }

 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int size = nums.size();

    int left = 0, right = nums.back() - nums.front() + 1;

    int answer = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int count = countPairsWithMaxDistance(nums, mid);

      if (count < k) {
        left = mid + 1;
      } else {
        answer = mid;
        right = mid;
      }
    }

    return answer;
  }
};