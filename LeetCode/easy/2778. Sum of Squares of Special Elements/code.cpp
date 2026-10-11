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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int sumOfSquares(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    for (int i = 0; i < size; i++) {
      if (size % (i + 1) == 0) {
        answer += nums[i] * nums[i];
      }
    }
    return answer;
  }
};