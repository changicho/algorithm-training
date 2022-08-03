#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int size = nums.size();

    vector<int> countPlus(32, 0), countMinus(32, 0);
    for (int& num : nums) {
      for (int i = 0; i < 32; i++) {
        bool isPlus = (num & (1 << i)) > 0;

        if (isPlus) {
          countPlus[i]++;
        } else {
          countMinus[i]++;
        }
      }
    }

    int count = 0;
    for (int i = 0; i < 32; i++) {
      count += countPlus[i] * countMinus[i];
    }

    return count;
  }
};