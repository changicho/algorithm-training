#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use index

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int index = 0;
    for (int num : nums) {
      if (index < 2 || num > nums[index - 2]) {
        nums[index] = num;
        index++;
      }
    }

    return index;
  }
};

// use map

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    map<int, int> counts;

    for (int num : nums) {
      counts[num] += 1;
    }

    int index = 0;
    for (pair<int, int> cur : counts) {
      for (int i = 0; i < min(cur.second, 2); i++) {
        nums[index] = cur.first;
        index++;
      }
    }

    return index;
  }
};