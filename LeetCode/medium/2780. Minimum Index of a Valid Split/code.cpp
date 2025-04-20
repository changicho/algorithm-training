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

// use Boyer-Moore Majority Voting Algorithm
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumIndex(vector<int> &nums) {
    int size = nums.size();

    int target = nums[0], count = 0;
    for (int &num : nums) {
      if (num == target) {
        count++;
      } else {
        count--;
      }
      if (count == 0) {
        target = num;
        count = 1;
      }
    }
    count = 0;
    for (int &num : nums) {
      if (num == target) count++;
    }

    int left = 0, right = count;
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] == target) {
        left++;
        right--;
      }
      int leftSize = i + 1, rightSize = size - (i + 1);

      if (left >= (leftSize / 2) + 1 && right >= (rightSize / 2) + 1) {
        return i;
      }
    }
    return -1;
  }
};