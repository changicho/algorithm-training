#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(N * log_10(M))
// space : O(N)
class Solution {
 private:
  int getDigit(int num) {
    int ret = 0;
    while (num > 0) {
      ret += num % 10;
      num /= 10;
    }
    return ret;
  }

 public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, int> um;

    int answer = -1;
    for (int& num : nums) {
      int digit = getDigit(num);

      if (um.count(digit)) {
        answer = max(answer, num + um[digit]);
      }
      um[digit] = max(um[digit], num);
    }
    return answer;
  }
};