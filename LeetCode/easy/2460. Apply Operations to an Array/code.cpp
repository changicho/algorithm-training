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
  vector<int> applyOperations(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }
    int index = 0;
    for (int i = 0, j = 0; i < size; i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[j]);
        j++;
      }
    }
    return nums;
  }
};