#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int size = nums.size();
    long long answer = 0;

    for (int left = 0, right = 0; right < size; right++) {
      if (nums[right] < minK || maxK < nums[right]) {
        left = right + 1;
      }

      answer += right - left + 1;
    }
    return answer;
  }
};