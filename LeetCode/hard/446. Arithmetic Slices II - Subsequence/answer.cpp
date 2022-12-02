#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int size = nums.size();

    long long answer = 0;
    // key : diff, val : subsequences count
    vector<unordered_map<long long, int>> counts(size);
    for (int i = 1; i < size; i++) {
      for (int prev = 0; prev < i; prev++) {
        long long diff = (long long)nums[i] - (long long)nums[prev];

        int beforeCount = 0;
        if (counts[prev].find(diff) != counts[prev].end()) {
          beforeCount = counts[prev][diff];
        }

        counts[i][diff] += beforeCount + 1;
        answer += beforeCount;
      }
    }

    return (int)answer;
  }
};