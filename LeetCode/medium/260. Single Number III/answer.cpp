#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, int> um;

    for (int& num : nums) {
      um[num] += 1;
      if (um[num] == 2) um.erase(num);
    }

    vector<int> ret;
    for (auto pair : um) {
      ret.emplace_back(pair.first);
    }

    return ret;
  }
};

// use bit mask

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    long bitmask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    int diff = (bitmask & -bitmask);

    vector<int> rets = {0, 0};
    for (int& num : nums) {
      if ((num & diff) == 0) {
        rets[0] ^= num;
      } else {
        rets[1] ^= num;
      }
    }
    return rets;
  }
};