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
  int countHillValley(vector<int>& nums) {
    int size = nums.size();

    int hill = 0;
    int valley = 0;
    for (int i = 1; i < size - 1; i++) {
      while (i < size - 1 && nums[i - 1] == nums[i]) {
        i++;
      }
      if (i == size - 1) break;
      int before = nums[i - 1];
      int cur = nums[i];
      while (i < size - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
      if (i == size - 1) break;
      int next = nums[i + 1];

      if (before < cur && cur > next) {
        hill++;
      }
      if (before > cur && cur < next) {
        valley++;
      }
    }

    return hill + valley;
  }
};

// use one pass with ignore same value
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int size = nums.size();

    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 1; i < size; i++) {
      if (nums[i - 1] == nums[i]) continue;
      arr.push_back(nums[i]);
    }

    int hill = 0;
    int valley = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
        hill++;
      }
      if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) {
        valley++;
      }
    }

    return hill + valley;
  }
};