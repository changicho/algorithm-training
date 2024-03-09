#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use KMP
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    for (int i = 0; i < nums.size() - 1; i++) {
      int cur = 0;
      if (nums[i] < nums[i + 1]) {
        cur = 1;
      } else if (nums[i] > nums[i + 1]) {
        cur = -1;
      }
      nums[i] = cur;
    }

    nums.pop_back();
    int size = nums.size(), pSize = pattern.size();
    vector<int> pIndexes(pSize, 0);

    int ret = 0;

    for (int i = 1, pI = 0; i < pSize; i++) {
      while (pI > 0 && pattern[i] != pattern[pI]) {
        pI = pIndexes[pI - 1];
      }
      if (pattern[i] == pattern[pI]) {
        pI++;
        pIndexes[i] = pI;
      }
    }

    for (int i = 0, pI = 0; i < size; i++) {
      while (pI > 0 && nums[i] != pattern[pI]) {
        pI = pIndexes[pI - 1];
      }

      if (nums[i] == pattern[pI]) {
        if (pI == pSize - 1) {
          ret++;

          pI = pIndexes[pI];
        } else {
          pI++;
        }
      }
    }

    return ret;
  }
};