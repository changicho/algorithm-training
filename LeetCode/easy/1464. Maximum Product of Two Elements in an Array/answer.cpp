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
  int maxProduct(vector<int>& nums) {
    int size = nums.size();

    int first = 0, second = 0;

    for (int& num : nums) {
      if (num >= first) {
        second = first;
        first = num;
      } else if (num > second) {
        second = num;
      }
    }
    return (first - 1) * (second - 1);
  }
};