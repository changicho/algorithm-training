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

// math
// time : O(1)
// space : O(1)
class Solution {
 public:
  long long countCommas(long long n) {
    long long cur = 1000;
    long long limit = 1000 * 1000;
    long long count = 1;
    long long answer = 0;
    while (cur <= n) {
      answer += (min(n, limit - 1) - (cur - 1)) * count;

      cur *= 1000;
      count++;
      if (limit >= 1e15) {
        limit = 1e16;
      } else {
        limit *= 1000;
      }
    }
    return answer;
  }
};