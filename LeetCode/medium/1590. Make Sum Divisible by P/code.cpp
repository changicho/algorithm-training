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

// use prefix sum mod
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    int size = nums.size();
    int sum = 0;

    for (int& num : nums) {
      sum = (sum + num) % p;
    }

    int diff = sum % p;
    if (diff == 0) return 0;

    unordered_map<int, int> beforeI;
    beforeI[0] = -1;
    int prefixSum = 0;
    int answer = size;

    for (int i = 0; i < size; i++) {
      prefixSum = (prefixSum + nums[i]) % p;

      int needed = (prefixSum - diff + p) % p;

      if (beforeI.count(needed) > 0) {
        answer = min(answer, i - beforeI[needed]);
      }

      beforeI[prefixSum] = i;
    }

    return answer == size ? -1 : answer;
  }
};
