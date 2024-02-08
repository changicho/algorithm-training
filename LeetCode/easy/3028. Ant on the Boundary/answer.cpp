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
  int returnToBoundaryCount(vector<int>& nums) {
    int answer = 0;
    int curX = 0;
    for (int& move : nums) {
      curX += move;

      if (curX == 0) answer++;
    }
    return answer;
  }
};