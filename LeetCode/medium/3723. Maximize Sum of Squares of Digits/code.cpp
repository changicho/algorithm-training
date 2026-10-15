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

// greedy
// time : O(N)
// space : O(N)
class Solution {
 public:
  string maxSumOfSquares(int num, int sum) {
    string answer(num, '0');
    if ((sum == 0) || (num * 9 < sum)) return "";

    for (int i = 0; i < num; i++) {
      int d = min(9, sum);

      answer[i] = (d + '0');
      sum -= d;
    }

    if (sum > 0) return "";
    return answer;
  }
};