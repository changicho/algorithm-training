#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxSpending(vector<vector<int>>& values) {
    vector<int> nums;
    for(vector<int> &row : values){
      for(int &num : row){
        nums.push_back(num);
      }
    }
    sort(nums.begin(), nums.end());

    long long answer = 0, day = 1;
    for (int& b : nums) {
      answer += day * b;
      day++;
    }
    return answer;
  }
};