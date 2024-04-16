#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use two sliding window
// time : O(N)
// space : O(K)
class Solution {
 private:
  int innerF(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<int, int> counts;

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[nums[right]]++;

      while (counts.size() > k && left <= right) {
        int target = nums[left];
        counts[target]--;

        if (counts[target] == 0) {
          counts.erase(target);
        }
        left++;
      }

      answer += (right - left + 1);
    }
    return answer;
  }

 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return innerF(nums, k) - innerF(nums, k - 1);
  }
};

// use one sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    int size = nums.size();

    unordered_map<int, int> counts;

    int prefixCount = 0;
    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[nums[right]]++;
      if (counts[nums[right]] == 1) {
        k--;
      }

      if (k < 0) {
        counts[nums[left]]--;
        left++;
        k++;
        prefixCount = 0;
      }

      if (k == 0) {
        while (counts[nums[left]] > 1) {
          counts[nums[left]]--;
          left++;
          prefixCount++;
        }

        answer += (prefixCount + 1);
      }
    }
    return answer;
  }
};