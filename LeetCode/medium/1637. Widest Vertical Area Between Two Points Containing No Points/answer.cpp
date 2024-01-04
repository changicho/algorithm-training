#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(log_2(N))
class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    int answer = 0;
    int before = points[0][0];
    for (vector<int>& p : points) {
      int x = p[0];
      if (before != x) {
        answer = max(answer, x - before);
        before = x;
      }
    }
    return answer;
  }
};