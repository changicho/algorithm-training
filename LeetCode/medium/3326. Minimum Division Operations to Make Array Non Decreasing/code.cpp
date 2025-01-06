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

// use simulation
// time : O(N * sqrt(M))
// space : O(1)
class Solution {
 private:
  int calc(int cur) {
    int limit = sqrt(cur);

    for (int i = 2; i <= limit; i++) {
      if (cur % i != 0) continue;

      return i;
    }

    return -1;
  }

 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    int next = INT_MAX;
    for (int i = size - 1; i >= 0; i--) {
      int cur = nums[i];

      while (cur > next) {
        answer++;
        cur = calc(cur);
      }

      if (cur == -1) return -1;

      next = cur;
    }
    return answer;
  }
};
