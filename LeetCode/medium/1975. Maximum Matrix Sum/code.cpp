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

// use greedy one pass
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int minimumAbs = INT_MAX;
    int negative = 0;

    for (vector<int>& row : matrix) {
      for (int& num : row) {
        sum += abs(num);

        if (num < 0) {
          negative++;
        }

        minimumAbs = min(minimumAbs, abs(num));
      }
    }

    if (negative % 2 == 1) {
      sum -= 2 * minimumAbs;
    }

    return sum;
  }
};