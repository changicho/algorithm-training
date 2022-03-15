#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> mods;  // mod, count

    // init value
    mods[0] = 1;

    int sum = 0;
    int answer = 0;
    for (int& num : nums) {
      sum += num;

      if (sum < 0) sum = k + (sum % k);

      int target = (sum % k);
      if (mods.count(target) > 0) {
        answer += mods[target];
      }

      mods[target]++;
    }

    return answer;
  }
};