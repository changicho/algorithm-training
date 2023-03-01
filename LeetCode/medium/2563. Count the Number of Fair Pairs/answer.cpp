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
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int size = nums.size();

    long long answer = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      int leftI = lower_bound(nums.begin() + (i + 1), nums.end(), lower - cur) -
                  nums.begin();
      int rightI =
          upper_bound(nums.begin() + (i + 1), nums.end(), upper - cur) -
          nums.begin();

      int curCount = rightI - leftI;
      answer += curCount;
    }

    return answer;
  }
};