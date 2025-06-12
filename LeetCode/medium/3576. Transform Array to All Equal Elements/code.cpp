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

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool check(vector<int> nums, int k, int target) {
    int size = nums.size();

    int count = 0;
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] != target) {
        nums[i] *= -1;
        nums[i + 1] *= -1;
        count++;
      }
    }

    if (nums[size - 1] != target) return false;
    return count <= k;
  }

 public:
  bool canMakeEqual(vector<int>& nums, int k) {
    bool first = check(nums, k, 1);
    bool second = check(nums, k, -1);

    return first || second;
  }
};