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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int size = nums.size();

    int answer = INT_MAX;
    for (int i = 0; i < size; i++) {
      if (nums[i] == target) {
        answer = min(answer, abs(start - i));
      }
    }
    return answer;
  }
};