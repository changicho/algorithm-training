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

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  bool check(vector<vector<int>>& squares, double lineY, double totalArea) {
    double area = 0;

    for (vector<int>& s : squares) {
      double x = s[0], y = s[1], l = s[2];

      if (y < lineY) {
        area += l * min(lineY - y, l);
      }
    }

    return area >= totalArea / 2;
  }

 public:
  double separateSquares(vector<vector<int>>& squares) {
    double left = 0, right = 0;

    double totalArea = 0;
    for (vector<int>& s : squares) {
      double x = s[0], y = s[1], l = s[2];
      totalArea += l * l;
      right = max(right, y + l);
    }

    double answer = -1;
    while (abs(right - left) > 1e-5) {
      double mid = left + (right - left) / 2;

      if (check(squares, mid, totalArea)) {
        right = mid;
        answer = mid;
      } else {
        left = mid;
      }
    }

    return answer;
  }
};