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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    int size = nums.size();

    int first = min(nums[1], nums[2]);
    int second = max(nums[1], nums[2]);
    for (int i = 3; i < size; i++) {
      if (first >= nums[i]) {
        second = first;
        first = nums[i];
      } else if (second >= nums[i]) {
        second = nums[i];
      }
    }

    return nums[0] + first + second;
  }
};

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    int size = nums.size();

    int answer = INT_MAX;
    for (int i = 1; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        answer = min(answer, nums.front() + nums[i] + nums[j]);
      }
    }

    return answer;
  }
};