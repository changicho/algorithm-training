#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int size = nums.size();

    int answer = INT_MAX;

    unordered_map<int, int> rights;
    rights[0] = 0;
    for (int i = size - 1, temp = 0; i >= 0; i--) {
      temp += nums[i];
      rights[temp] = size - i;
    }

    if (rights.count(x) > 0) {
      answer = min(answer, rights[x]);
    }
    for (int i = 0, temp = 0; i < size; i++) {
      temp += nums[i];
      int target = x - temp;

      if (rights.count(target) > 0 && rights[target] + i + 1 <= size) {
        answer = min(answer, i + 1 + rights[target]);
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int size = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int answer = INT_MAX;

    int target = sum - x;
    if (target == 0) {
      answer = size;
    }

    for (int right = 0, left = 0, temp = 0; right < size; right++) {
      temp += nums[right];

      while (temp > target && left < right) {
        temp -= nums[left];
        left++;
      }

      if (temp == target) {
        answer = min(answer, (left) + (size - 1 - right));
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};