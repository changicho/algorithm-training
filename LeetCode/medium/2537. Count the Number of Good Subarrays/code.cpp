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

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    int size = nums.size();

    long long answer = 0;
    unordered_map<int, int> count;
    int pairs = 0;
    for (int left = 0, right = 0; right < size; right++) {
      count[nums[right]]++;
      pairs += count[nums[right]] - 1;

      while (k <= pairs) {
        count[nums[left]]--;
        pairs -= count[nums[left]];
        left++;
      }

      answer += left;
    }
    return answer;
  }
};