#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    multiset<int> bigger;
    for (int i = size / 2; i < size; i++) {
      int num = nums[i];
      bigger.insert(num);
    }

    int count = 0;
    for (int i = 0; i < size / 2; i++) {
      auto it = bigger.lower_bound(nums[i] * 2);

      if (it != bigger.end()) {
        bigger.erase(it);
        count += 2;
      }
    }

    return count;
  }
};