#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> us;

    vector<int> answer;
    for (int& num : nums) {
      if (us.count(num) == 0) {
        us.insert(num);
      } else {
        answer.emplace_back(num);
      }
    }

    return answer;
  }
};

// use visited array

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> answer;

    for (int& num : nums) {
      int absolute = abs(num);

      if (nums[absolute - 1] < 0) {
        answer.push_back(absolute);
      }

      nums[absolute - 1] = -nums[absolute - 1];
    }
    return answer;
  }
};