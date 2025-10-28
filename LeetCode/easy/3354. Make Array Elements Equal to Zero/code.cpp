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

// use prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countValidSelections(vector<int>& nums) {
    int size = nums.size();

    int leftSum = 0;
    int rightSum = accumulate(nums.begin(), nums.end(), 0);

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] != 0) {
        leftSum += nums[i];
        rightSum -= nums[i];
      } else {
        if (leftSum == rightSum) answer += 2;
        if (abs(leftSum - rightSum) == 1) answer++;
      }
    }
    return answer;
  }
};

// use prefix sum
// time : O(N^2 * M)
// space : O(1)
class Solution {
 private:
  bool check(vector<int> nums, int index, int dir) {
    int size = nums.size();

    index += dir;
    while (index >= 0 && index < size) {
      if (nums[index] > 0) {
        nums[index]--;
        dir *= -1;
      }

      index += dir;
    }

    for (int i = 0; i < size; i++) {
      if (nums[i] > 0) return false;
    }
    return true;
  }

 public:
  int countValidSelections(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        answer += check(nums, i, +1);
        answer += check(nums, i, -1);
      }
    }
    return answer;
  }
};