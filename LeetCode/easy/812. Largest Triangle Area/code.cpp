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

// use brute force & math
// time : O(N^3)
// space : O(1)
class Solution {
 private:
  double getArea(vector<int> &a, vector<int> &b, vector<int> &c) {
    return abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - b[0] * a[1] -
               c[0] * b[1] - a[0] * c[1]) /
           2.0;
  }

 public:
  double largestTriangleArea(vector<vector<int>> &points) {
    double answer = 0;

    int size = points.size();

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        for (int k = j + 1; k < size; k++) {
          answer = max(answer, getArea(points[i], points[j], points[k]));
        }
      }
    }

    return answer;
  }
};