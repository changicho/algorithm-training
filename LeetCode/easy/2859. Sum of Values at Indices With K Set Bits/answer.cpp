#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  int count(int num) {
    int count = 0;
    while (num > 0) {
      count += num % 2;
      num /= 2;
    }
    return count;
  }

 public:
  int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int size = nums.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (count(i) == k) {
        answer += nums[i];
      }
    }
    return answer;
  }
};