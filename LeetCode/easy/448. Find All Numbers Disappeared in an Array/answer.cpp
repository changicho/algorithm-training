#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    // 1. sort nums
    sort(nums.begin(), nums.end());

    vector<int> answer;

    // 2. fill 1 ~ nums.front()
    if (nums.front() != 1) {
      for (int i = 1; i < nums.front(); i++) {
        answer.emplace_back(i);
      }
    }

    // 3. fill nums.front() ~ nums.back()
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] == 1) continue;

      for (int num = nums[i - 1] + 1; num < nums[i]; num++) {
        answer.emplace_back(num);
      }
    }

    // 4. fill nums.back() ~ n
    if (nums.back() != nums.size()) {
      for (int i = nums.back() + 1; i <= nums.size(); i++) {
        answer.emplace_back(i);
      }
    }

    return answer;
  }
};

// use hash set

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> answer;

    int size = nums.size();
    unordered_set<int> us;

    for (int& num : nums) {
      us.insert(num);
    }

    for (int num = 1; num <= size; num++) {
      if (!us.count(num)) {
        answer.push_back(num);
      }
    }

    return answer;
  }
};

// use placing elements at correct Index

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer;
    for (int i = 0; i < size; i++) {
      int num = nums[i];

      // pass case : nums[num - 1] == num
      // swap until nums[num - 1] is pass case
      while (nums[num - 1] != num) {
        swap(nums[i], nums[num - 1]);
        num = nums[i];
      }
    }

    // count missing number
    for (int i = 1; i <= size; i++) {
      if (i != nums[i - 1]) answer.push_back(i);
    }

    return answer;
  }
};

// use Space-Optimized using In-place modification

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer;

    for (int& num : nums) {
      // set nums[num - 1] value to minus
      // if ith value is minus, it is in the nums
      nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
    }

    for (int i = 0; i < size; i++) {
      if (nums[i] > 0) {
        answer.push_back(i + 1);
      }
    }

    return answer;
  }
};