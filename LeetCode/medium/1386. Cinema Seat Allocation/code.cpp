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

// bitmask by row
// time : O(M)
// space : O(M)
class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    long long answer = (long long)n * 2;

    unordered_map<int, vector<int>> um;

    // 01111000000, 0001111000, 0000011110
    vector<int> mask = {30, 120, 480};

    for (vector<int>& r : reservedSeats) {
      int y = r[0] - 1, x = r[1] - 1;

      um[y].push_back(x);
    }

    for (auto [key, val] : um) {
      int board = 0;

      for (int x : val) {
        board |= (1 << x);
      }

      int curCase = 0;
      for (int& bit : mask) {
        if ((board & bit) == 0) {
          curCase++;
          board += bit;
        }
      }

      answer -= 2 - curCase;
    }

    return answer;
  }
};