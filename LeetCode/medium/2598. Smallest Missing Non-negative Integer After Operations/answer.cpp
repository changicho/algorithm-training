#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use mod count
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findSmallestInteger(vector<int> &nums, int value) {
    unordered_map<int, int> mods;
    for (int i = 0; i < value; i++) {
      mods[i] = 0;
    }

    for (int &num : nums) {
      int mod = num % value;
      if (mod < 0) mod += value;
      mods[mod]++;
    }

    int loopCount = INT_MAX;
    for (auto &[key, val] : mods) {
      loopCount = min(loopCount, val);
    }

    int start = (loopCount)*value;
    for (auto &[key, val] : mods) {
      val -= loopCount;
    }
    for (int i = 0; i < value; i++) {
      if (mods[i] == 0) return i + start;
    }
    return 0;
  }
};