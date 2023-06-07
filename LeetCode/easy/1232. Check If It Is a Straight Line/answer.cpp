#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use sort & diff
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int size = coordinates.size();
    sort(coordinates.begin(), coordinates.end(),
         [](vector<int> &a, vector<int> &b) {
           if (a[0] == b[0]) {
             return a[1] < b[1];
           }
           return a[0] < b[0];
         });

    int xDiff = coordinates[1][0] - coordinates[0][0];
    int yDiff = coordinates[1][1] - coordinates[0][1];
    int g = gcd(xDiff, yDiff);

    xDiff /= g;
    yDiff /= g;

    for (int i = 1; i < size; i++) {
      int curXDiff = coordinates[i][0] - coordinates[i - 1][0];
      int curYDiff = coordinates[i][1] - coordinates[i - 1][1];

      int g = gcd(curXDiff, curYDiff);
      curXDiff /= g;
      curYDiff /= g;

      if (xDiff != curXDiff || yDiff != curYDiff) {
        if (xDiff == 0 && curXDiff == 0) continue;
        if (yDiff == 0 && curYDiff == 0) continue;
        return false;
      }
    }
    return true;
  }
};

// use check diff
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int size = coordinates.size();

    int xDiff = coordinates[1][0] - coordinates[0][0];
    int yDiff = coordinates[1][1] - coordinates[0][1];

    for (int i = 1; i < size; i++) {
      int curXDiff = coordinates[i][0] - coordinates[i - 1][0];
      int curYDiff = coordinates[i][1] - coordinates[i - 1][1];

      if (curXDiff * yDiff != xDiff * curYDiff) {
        return false;
      }
    }
    return true;
  }
};