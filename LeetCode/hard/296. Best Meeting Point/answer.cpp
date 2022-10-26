#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search & suffix sum
// time : O(R * C * log_2(R * C))
// space : O(R * C)
class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<int> pointXs, pointYs;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        pointXs.push_back(x);
        pointYs.push_back(y);
      }
    }

    sort(pointXs.begin(), pointXs.end());
    sort(pointYs.begin(), pointYs.end());

    vector<int> suffixX(pointXs.size() + 1), suffixY(pointYs.size() + 1);
    for (int i = 0; i < pointXs.size(); i++) {
      suffixX[i + 1] = suffixX[i] + pointXs[i];
    }
    for (int i = 0; i < pointYs.size(); i++) {
      suffixY[i + 1] = suffixY[i] + pointYs[i];
    }

    int answer = INT_MAX;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int xI =
            lower_bound(pointXs.begin(), pointXs.end(), x) - pointXs.begin();
        int yI =
            lower_bound(pointYs.begin(), pointYs.end(), y) - pointYs.begin();

        int cur = 0;
        cur += abs(suffixX[xI] - xI * x) + abs(suffixX.back() - suffixX[xI] -
                                               (int(pointXs.size()) - xI) * x);

        cur += abs(suffixY[yI] - yI * y) + abs(suffixY.back() - suffixY[yI] -
                                               (int(pointYs.size()) - yI) * y);

        answer = min(answer, cur);
      }
    }
    return answer;
  }
};

// use sort & median
// time : O(R * C * log_2(R * C))
// space : O(R * C)
class Solution {
 private:
  int getDistSum(vector<int>& points, int axis) {
    int distance = 0;
    for (int& point : points) {
      distance += abs(axis - point);
    }
    return distance;
  }

 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<int> pointXs, pointYs;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        pointXs.push_back(x);
        pointYs.push_back(y);
      }
    }

    sort(pointXs.begin(), pointXs.end());
    sort(pointYs.begin(), pointYs.end());

    // get median
    int y = pointYs[pointYs.size() / 2];
    int x = pointXs[pointXs.size() / 2];

    int answer = getDistSum(pointYs, y) + getDistSum(pointXs, x);
    return answer;
  }
};

// use counting sort & median
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  int getDistSum(vector<int>& points, int axis) {
    int distance = 0;
    for (int& point : points) {
      distance += abs(axis - point);
    }
    return distance;
  }

 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<int> pointXs, pointYs;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;
        pointYs.push_back(y);
      }
    }

    for (int x = 0; x < cols; x++) {
      for (int y = 0; y < rows; y++) {
        if (grid[y][x] == 0) continue;
        pointXs.push_back(x);
      }
    }

    // get median
    int y = pointYs[pointYs.size() / 2];
    int x = pointXs[pointXs.size() / 2];

    int answer = getDistSum(pointYs, y) + getDistSum(pointXs, x);
    return answer;
  }
};