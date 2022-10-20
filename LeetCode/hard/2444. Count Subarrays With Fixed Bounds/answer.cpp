#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int size = nums.size();
    long long answer = 0;
    int lastOutIdx = -1, lastMinIdx = -1, lastMaxIdx = -1;

    for (int i = 0; i < size; ++i) {
      int num = nums[i];

      if (num < minK || maxK < num) {
        lastOutIdx = i;
        continue;
      }
      if (num == minK) lastMinIdx = i;
      if (num == maxK) lastMaxIdx = i;

      long long curLength = min(lastMinIdx, lastMaxIdx) - lastOutIdx;
      if (curLength <= 0) continue;
      answer += curLength;
    }

    return answer;
  }
};