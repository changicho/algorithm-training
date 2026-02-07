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

// sort & two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    int answer = size;

    for (int left = 0, right = 0; left < size; left++) {
      while (right < size && nums[right] <= (long long)nums[left] * k) {
        right++;
      }

      int curCount = left + (size - right);

      answer = min(answer, curCount);
    }
    return answer;
  }
};