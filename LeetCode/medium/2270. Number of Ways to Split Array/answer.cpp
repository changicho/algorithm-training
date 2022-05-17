#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int size = nums.size();

    vector<long long> prefixSum(size + 1, 0), rPrefixSum(size + 1, 0);
    // prefixSum[i] = ~ nums[i-1]
    // rPrefixSum[i] = nums[i] ~
    for (int i = 0; i < size; i++) {
      int rI = size - 1 - i;

      prefixSum[i + 1] = prefixSum[i] + nums[i];
      rPrefixSum[rI] = rPrefixSum[rI + 1] + nums[rI];
    }

    int sameCount = 0;
    for (int i = 0; i < size - 1; i++) {
      if (prefixSum[i + 1] >= rPrefixSum[i + 1]) {
        sameCount++;
      }
    }
    return sameCount;
  }
};

// use pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int size = nums.size();

    long long curSum = 0;
    long long beforeSum = 0;
    for (int& num : nums) {
      beforeSum += num;
    }

    int sameCount = 0;
    for (int i = 0; i < size - 1; i++) {
      curSum += nums[i];
      beforeSum -= nums[i];

      if (curSum >= beforeSum) sameCount++;
    }
    return sameCount;
  }
};