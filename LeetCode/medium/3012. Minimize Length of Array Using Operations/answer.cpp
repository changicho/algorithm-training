#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use find minimum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumArrayLength(vector<int>& nums) {
    int minimum = *min_element(nums.begin(), nums.end());
    for (int& num : nums) {
      if (num % minimum > 0) {
        return 1;
      }
    }

    int minCount = count(nums.begin(), nums.end(), minimum);
    return (minCount + 1) / 2;
  }
};