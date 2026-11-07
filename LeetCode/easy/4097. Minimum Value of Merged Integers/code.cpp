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

// convert
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minMergedInteger(vector<int>& nums) {
    int size = nums.size();
    int answer = INT_MAX;

    for (int i = 0; i < size; i += 2) {
      int cur = nums[i] * pow(10, (int)log10(nums[i + 1]) + 1) + nums[i + 1];

      answer = min(answer, cur);
    }
    return answer;
  }
};