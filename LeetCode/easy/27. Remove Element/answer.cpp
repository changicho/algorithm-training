#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> newArr;

    for (int num : nums) {
      if (num != val) {
        newArr.push_back(num);
      }
    }

    nums = newArr;

    return newArr.size();
  }
};