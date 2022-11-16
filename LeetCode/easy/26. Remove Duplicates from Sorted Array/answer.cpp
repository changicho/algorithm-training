#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(N)
// space : O(N)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    bool counts[201] = {
        false,
    };

    for (int num : nums) {
      counts[num + 100] = true;
    }

    nums.clear();
    nums.resize(0);
    for (int i = 0; i <= 200; i++) {
      if (counts[i]) {
        nums.push_back(i - 100);
      }
    }

    return nums.size();
  }
};

// use STL
// time : O(N)
// space : O(N)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
  }
};

// use extra space
// time : O(N)
// space : O(N)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    vector<int> ret;
    for (int& num : nums) {
      if (!ret.empty() && ret.back() == num) {
        continue;
      }
      ret.push_back(num);
    }

    nums = ret;
    return ret.size();
  }
};

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    int insertIndex = 1;
    for (int i = 1; i < size; i++) {
      if (nums[i - 1] != nums[i]) {
        nums[insertIndex] = nums[i];
        insertIndex++;
      }
    }
    return insertIndex;
  }
};