#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation (brute force)
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  bool isSorted(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] > nums[i + 1]) return false;
    }
    return true;
  }

 public:
  int minimumPairRemoval(vector<int>& nums) {
    int answer = 0;
    while (!isSorted(nums)) {
      int target = 0;
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[target] + nums[target + 1] > nums[i] + nums[i + 1]) {
          target = i;
        }
      }

      nums[target] = nums[target] + nums[target + 1];
      nums.erase(nums.begin() + target + 1);

      answer++;
    }

    return answer;
  }
};