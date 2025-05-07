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

// use one pass (extra space)
// time : O(N)
// space : O(M)
class Solution {
 public:
  vector<int> buildArray(vector<int> &nums) {
    int size = nums.size();
    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
      arr[i] = nums[nums[i]];
    }

    return arr;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> buildArray(vector<int> &nums) {
    int size = nums.size();

    for (int &num : nums) {
      num += 1000 * (nums[num] % 1000);
    }
    for (int &num : nums) {
      num /= 1000;
    }

    return nums;
  }
};