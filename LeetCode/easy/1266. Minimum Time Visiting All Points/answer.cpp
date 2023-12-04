#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getDist(vector<int> &a, vector<int> &b) {
    int xDiff = abs(a[0] - b[0]);
    int yDiff = abs(a[1] - b[1]);
    return max(xDiff, yDiff);
  }

 public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int answer = 0;
    vector<int> cur = points[0];

    for (vector<int> &p : points) {
      answer += getDist(p, cur);
      cur = p;
    }
    return answer;
  }
};