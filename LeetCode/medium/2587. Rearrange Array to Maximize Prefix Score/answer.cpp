#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxScore(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    long long score = 0;
    int answer = 0;
    for (int& num : nums) {
      score += num;
      if (score <= 0) break;
      answer++;
    }
    return answer;
  }
};