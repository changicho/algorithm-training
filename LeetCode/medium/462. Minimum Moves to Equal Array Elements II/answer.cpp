#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use ternary search
// time : O(N * log_3(N))
// space : O(1)
class Solution {
 private:
  long long getDiff(vector<int> &nums, int key) {
    long long diff = 0;
    for (int &n : nums) {
      diff += abs(key - n);
    }
    return diff;
  }

 public:
  int minMoves2(vector<int> &nums) {
    int size = nums.size();

    long long answer = getDiff(nums, nums.front());

    int rangeStart = -1e9, rangeEnd = +1e9;
    while (rangeStart + 3 <= rangeEnd) {
      int left = (2 * rangeStart + rangeEnd) / 3;
      int right = (rangeStart + 2 * rangeEnd) / 3;

      long long costL = getDiff(nums, left);
      long long costR = getDiff(nums, right);

      if (costL < costR) {
        // pick leftPart
        rangeEnd = right;
        answer = min(answer, costL);
      } else {
        // pick rightPart
        rangeStart = left;
        answer = min(answer, costR);
      }
    }

    return (int)answer;
  }
};

// use find median
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int median = nums[size / 2];
    int answer = 0;
    for (int &n : nums) {
      answer += abs(n - median);
    }

    return answer;
  }
};

// use find diff
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size / 2; i++) {
      answer += nums[size - 1 - i] - nums[i];
    }

    return answer;
  }
};

// use find nth element
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minMoves2(vector<int> &nums) {
    int size = nums.size();
    int answer = 0;
    nth_element(nums.begin(), nums.begin() + (size / 2), nums.end());

    int median = nums[size / 2];
    for (int &n : nums) {
      answer += abs(n - median);
    }
    return answer;
  }
};