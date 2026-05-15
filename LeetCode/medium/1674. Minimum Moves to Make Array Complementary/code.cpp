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

// count diff
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    int size = nums.size();
    vector<int> diff(2 * limit + 2, 0);

    for (int i = 0; i < size / 2; ++i) {
      int a = min(nums[i], nums[size - 1 - i]);
      int b = max(nums[i], nums[size - 1 - i]);

      // 2 ~ (1+a) ~ (a+b) ~ (a+b+1) ~ (b+limit+1) ~ (2*limit)

      diff[2] += 2;
      diff[1 + a] -= 1;
      diff[a + b] -= 1;
      diff[a + b + 1] += 1;
      diff[b + limit + 1] += 1;
    }

    int answer = size;
    int cur = 0;

    for (int c = 2; c <= 2 * limit; ++c) {
      cur += diff[c];
      answer = min(answer, cur);
    }

    return answer;
  }
};