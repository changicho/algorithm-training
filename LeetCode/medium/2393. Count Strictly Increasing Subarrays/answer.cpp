#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  long long calculate(int size) { return ((long long)size) * (size + 1) / 2; }

 public:
  long long countSubarrays(vector<int>& nums) {
    int size = nums.size();
    long long answer = 0;

    int before = 0;
    int count = 0;
    for (int& num : nums) {
      if (before >= num) {
        answer += calculate(count);
        count = 0;
        before = 0;
      }

      count++;
      before = num;
    }

    answer += calculate(count);
    return answer;
  }
};