#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  int reverse(int num) {
    int result = 0;
    while (num > 0) {
      result = result * 10 + num % 10;
      num /= 10;
    }

    return result;
  }

 public:
  int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> um;

    int answer = 0;
    for (int& num : nums) {
      int cur = num - reverse(num);

      answer += um[cur];
      answer %= MOD;

      um[cur]++;
    }

    return answer;
  }
};