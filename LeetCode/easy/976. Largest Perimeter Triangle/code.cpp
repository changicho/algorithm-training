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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end(), greater<int>());

    int answer = 0;

    for (int i = 0; i < size - 2; i++) {
      int a = nums[i], b = nums[i + 1], c = nums[i + 2];

      if (a < b + c) {
        return a + b + c;
      }
    }

    return 0;
  }
};