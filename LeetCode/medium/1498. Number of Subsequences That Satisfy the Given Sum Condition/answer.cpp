#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int answer = 0;

    int pows[100001] = {
        0,
    };
    pows[0] = 1;
    for (int i = 1; i <= size; i++) {
      pows[i] = pows[i - 1] * 2;
      pows[i] %= MOD;
    }

    int left = 0, right = size - 1;
    while (left <= right) {
      if (nums[left] + nums[right] <= target) {
        // in range left ~ right, suqSequence must contain nums[left]
        // length is (right - left + 1) : count of (left ~ right)
        // the case of subsequence size is pow(length - 1)

        int length = right - left + 1;
        answer += pows[length - 1];
        answer %= MOD;
        left++;
      } else {
        right--;
      }
    }

    return answer;
  }
};

// use sort & binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int answer = 0;

    int pows[100001] = {
        0,
    };
    pows[0] = 1;
    for (int i = 1; i <= size; i++) {
      pows[i] = pows[i - 1] * 2;
      pows[i] %= MOD;
    }

    for (int left = 0; left < size; left++) {
      int num = nums[left];
      int right = upper_bound(nums.begin(), nums.end(), target - num) -
                  nums.begin() - 1;

      if (right >= left) {
        // in range left ~ right, suqSequence must contain nums[left]
        // length is (right - left + 1) : count of (left ~ right)
        // the case of subsequence size is pow(length - 1)

        int length = right - left + 1;

        answer += pows[length - 1];
        answer %= MOD;
      }
    }

    return answer;
  }
};