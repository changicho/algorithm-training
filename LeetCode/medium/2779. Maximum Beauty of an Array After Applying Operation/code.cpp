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

// use binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = 0;

    for (int& num : nums) {
      int count = upper_bound(nums.begin(), nums.end(), num + 2 * k) -
                  lower_bound(nums.begin(), nums.end(), num);

      answer = max(answer, count);
    }

    return answer;
  }
};