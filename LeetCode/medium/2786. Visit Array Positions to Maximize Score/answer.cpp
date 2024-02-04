#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long maxScore(vector<int>& nums, int x) {
    int size = nums.size();

    long long even = nums.front() - (nums.front() % 2 ? x : 0);
    long long odd = nums.front() - (nums.front() % 2 ? 0 : x);

    for (int i = 1; i < size; i++) {
      if (nums[i] % 2 == 1) {
        odd = nums[i] + max(odd, even - x);
      } else {
        even = nums[i] + max(even, odd - x);
      }
    }

    return max(even, odd);
  }
};