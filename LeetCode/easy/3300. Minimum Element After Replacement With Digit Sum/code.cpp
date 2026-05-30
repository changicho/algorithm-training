#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// one pass
// time : O(N * log_10(M))
// space : O(1)
class Solution {
 public:
  int minElement(vector<int>& nums) {
    int answer = INT_MAX;

    for (int& num : nums) {
      int cur = 0;
      while (num > 0) {
        cur += num % 10;
        num /= 10;
      }

      answer = min(answer, cur);
    }
    return answer;
  }
};