#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    unordered_set<int> us(nums.begin(), nums.end());

    for (int left = 0; left < size; left++) {
      unordered_set<int> temp;
      for (int i = left; i < size; i++) {
        temp.insert(nums[i]);

        if (temp.size() == us.size()) answer++;
      }
    }

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int size = nums.size();
    int needNums = unordered_set<int>(nums.begin(), nums.end()).size();

    int answer = 0, left = 0;
    unordered_map<int, int> count;
    for (int right = 0; right < size; ++right) {
      count[nums[right]]++;
      if (count[nums[right]] == 1) {
        needNums--;
      }

      while (needNums == 0) {
        count[nums[left]]--;
        if (count[nums[left]] == 0) {
          needNums++;
        }
        left++;
      }
      answer += left;
    }
    return answer;
  }
};