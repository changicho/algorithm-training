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
  int minimumDeletions(vector<int>& nums) {
    int size = nums.size();
    int minI = 0, maxI = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] < nums[minI]) {
        minI = i;
      }
      if (nums[i] > nums[maxI]) {
        maxI = i;
      }
    }

    int answer = INT_MAX;
    int left = min(minI, maxI), right = max(minI, maxI);

    answer = min(
        {right + 1, left + 1 + (size - 1 - right) + 1, size - 1 - left + 1});

    return answer;
  }
};