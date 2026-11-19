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

// greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    int size = nums.size();
    if (size == 3) return 0;
    sort(nums.begin(), nums.end());

    int answer = INT_MAX;
    for (int i = 0; i < 3; i++) {
      int cur = nums[size - 1 - i] - nums[2 - i];
      answer = min(answer, cur);
    }
    return answer;
  }
};