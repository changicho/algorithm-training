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

// use sort
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int numberOfPairs(vector<vector<int>> &points) {
    int size = points.size();

    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
      if (a[0] == b[0]) return a[1] < b[1];
      return a[0] > b[0];
    });

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int x = points[i][0];
      int y = points[i][1];

      int minY = INT_MAX;
      for (int j = i + 1; j < size; j++) {
        int nx = points[j][0];
        int ny = points[j][1];

        if (ny >= minY || ny < y) continue;
        answer++;
        minY = ny;
      }
    }
    return answer;
  }
};