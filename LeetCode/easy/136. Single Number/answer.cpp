#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    nums.push_back(-30001);
    nums.push_back(30001);
    int size = nums.size();
    int answer = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < size - 1; i++) {
      if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) {
        answer = nums[i];
        break;
      }
    }

    return answer;
  }
};

// use xor

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int answer = 0;
    for (int num : nums) {
      answer ^= num;
    }
    return answer;
  }
};

// use set

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> s;

    for (int num : nums) {
      if (s.find(num) != s.end()) {
        s.erase(num);
      } else {
        s.insert(num);
      }
    }

    return *s.begin();
  }
};