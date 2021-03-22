#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    bool counts[20001] = {
        false,
    };

    for (int num : nums) {
      counts[num + 1000] = true;
    }

    int answer = 0;
    nums.clear();
    nums.resize(0);
    for (int i = 0; i <= 20000; i++) {
      if (counts[i]) {
        answer += 1;
        nums.push_back(i - 1000);
      }
    }

    return answer;
  }
};

// use STL

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
  }
};