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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int answer = 0;
    for (int& n : nums) {
      if (n == 1) {
        count++;
      } else {
        count = 0;
      }

      answer = max(answer, count);
    }
    return answer;
  }
};