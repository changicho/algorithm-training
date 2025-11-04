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

// use sort & binary search
// time : O((N + M) * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    int minimum = nums.front(), maximum = nums.back();

    int answer = 0;
    for (int num = minimum; num <= maximum; num++) {
      int rangeCount = upper_bound(nums.begin(), nums.end(), num + k) -
                       lower_bound(nums.begin(), nums.end(), num - k);

      int sameCount = upper_bound(nums.begin(), nums.end(), num) -
                      lower_bound(nums.begin(), nums.end(), num);
      int diff = rangeCount - sameCount;

      answer = max(answer, sameCount);
      answer = max(answer, sameCount + min(diff, numOperations));
    }
    return answer;
  }
};

// use prefix sum
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int count[100001] = {
        0,
    };
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for (int& num : nums) {
      count[num]++;

      minimum = min(minimum, num);
      maximum = max(maximum, num);
    }

    int prefixSum[100001] = {
        0,
    };
    prefixSum[0] = count[0];
    for (int num = minimum; num <= maximum; num++) {
      prefixSum[num] += prefixSum[num - 1] + count[num];
    }

    int answer = 0;
    for (int num = minimum; num <= maximum; num++) {
      int rangeCount = prefixSum[min(num + k, maximum)] -
                       (num - k - 1 >= minimum ? prefixSum[num - k - 1] : 0);

      int sameCount = count[num];
      int diff = rangeCount - sameCount;

      answer = max(answer, sameCount);
      answer = max(answer, sameCount + min(diff, numOperations));
    }
    return answer;
  }
};