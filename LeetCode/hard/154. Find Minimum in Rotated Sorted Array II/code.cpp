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

// binary search
// time : O(log_2(N)) or O(N)
// space : O(1)
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int size = nums.size();

    int left = 0, right = size - 1;
    int answer = nums[0];
    while (left <= right) {
      int mid = left + (right - left) / 2;

      answer = min(answer, nums[mid]);
      if (nums[mid] < nums[right]) {
        right = mid;
      } else if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right -= 1;
      }
    }

    return answer;
  }
};

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findMin(vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
  }
};