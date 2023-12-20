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
  int maxProductDifference(vector<int>& nums) {
    int size = nums.size();
    int m1 = INT_MIN, m2 = INT_MIN;
    int s1 = INT_MAX, s2 = INT_MAX;

    for (int& num : nums) {
      if (num >= m1) {
        m2 = m1;
        m1 = num;
      } else if (num > m2) {
        m2 = num;
      }

      if (num <= s1) {
        s2 = s1;
        s1 = num;
      } else if (num < s2) {
        s2 = num;
      }
    }

    return (m1 * m2) - (s1 * s2);
  }
};