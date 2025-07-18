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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxAdjacentDistance(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = nums[i];
      int next = nums[(i + 1) % size];

      answer = max(abs(cur - next), answer);
    }
    return answer;
  }
};