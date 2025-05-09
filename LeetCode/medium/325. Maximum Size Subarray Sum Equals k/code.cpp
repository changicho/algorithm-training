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

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<long long, int> leftMostIndexes;

    int answer = 0;
    long long sum = 0;
    leftMostIndexes[0] = -1;
    for (int i = 0; i < size; i++) {
      sum += nums[i];

      if (leftMostIndexes.count(sum - k)) {
        answer = max(answer, i - leftMostIndexes[sum - k]);
      }

      if (!leftMostIndexes.count(sum)) {
        leftMostIndexes[sum] = i;
      }
    }
    return answer;
  }
};