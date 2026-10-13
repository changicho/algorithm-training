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

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end(),
         [](int& a, int& b) { return abs(a) < abs(b); });

    long long answer = 0;
    for (int left = 0, right = size - 1; left <= right; left++, right--) {
      answer += nums[right] * nums[right];
      if (left < right) {
        answer -= nums[left] * nums[left];
      }
    }
    return answer;
  }
};

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    int size = nums.size();
    for (int& num : nums) {
      num *= num;
    }
    sort(nums.begin(), nums.end());

    long long minusPart =
        accumulate(nums.begin(), nums.begin() + size / 2, 0LL);
    long long plusPart = accumulate(nums.begin() + size / 2, nums.end(), 0LL);

    return plusPart - minusPart;
  }
};