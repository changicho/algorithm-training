#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// sort & one pass
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long largestPerimeter(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    long long answer = -1;
    long long sum = 0;
    int count = 0;

    for (int& num : nums) {
      count++;
      if (count >= 3 && num < sum) {
        answer = max(answer, sum + num);
      }
      sum += num;
    }

    return answer;
  }
};