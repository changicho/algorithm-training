#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use prefixSum with mod

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    int sum = 0, prevMod = 0;

    unordered_set<int> mods;

    for (int i = 0; i < size; i++) {
      sum += nums[i];

      int mod = sum % k;  // current mod

      // find x that (mod + x == k)
      if (mods.count(mod)) return true;
      mods.insert(prevMod);

      // update remain mod value
      // passing one element (subArray's size > 1)
      prevMod = mod;
    }

    return false;
  }
};

// use prefixSum with mod (index)

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mods;  // {mod, index}
    mods[0] = -1;

    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sum %= k;

      // store first case of mods
      if (mods.count(sum) == 0) {
        mods[sum] = i;
      }

      // calculate size of subArray
      if (i - mods[sum] > 1) return true;
    }

    return false;
  }
};