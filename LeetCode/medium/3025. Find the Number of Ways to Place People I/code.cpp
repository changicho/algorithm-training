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

// use brute force
// time : O(N^3)
// space : O(1)
class Solution {
 public:
  int numberOfPairs(vector<vector<int>> &points) {
    int size = points.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i == j) continue;

        // x,y
        vector<int> &a = points[i];
        vector<int> &b = points[j];

        if (a[0] > b[0] || a[1] < b[1]) continue;

        int left = a[0], right = b[0];
        int down = b[1], up = a[1];

        bool isFine = true;
        for (int k = 0; k < size; k++) {
          if (k == i || k == j) continue;

          vector<int> &p = points[k];

          if (left <= p[0] && p[0] <= right && down <= p[1] && p[1] <= up) {
            isFine = false;
          }
        }

        answer += isFine;
      }
    }

    return answer;
  }
};

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