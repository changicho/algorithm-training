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

// use axis count
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isInMiddle(pair<int, int>& p, int val) {
    if (p.first == p.second || p.first == val || p.second == val) return false;
    return true;
  }

  void change(pair<int, int>& p, int val) {
    p.first = min(p.first, val);
    p.second = max(p.second, val);
  }

 public:
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    vector<pair<int, int>> y2x(n + 1, {INT_MAX, INT_MIN});
    vector<pair<int, int>> x2y(n + 1, {INT_MAX, INT_MIN});

    for (vector<int>& b : buildings) {
      int y = b[0], x = b[1];

      change(y2x[y], x);
      change(x2y[x], y);
    }

    int answer = 0;
    for (vector<int>& b : buildings) {
      int y = b[0], x = b[1];

      if (isInMiddle(y2x[y], x) && isInMiddle(x2y[x], y)) answer++;
    }
    return answer;
  }
};