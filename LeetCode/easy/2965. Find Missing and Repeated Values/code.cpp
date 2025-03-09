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

// use count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int duplicated = -1, missed = -1;
    bool visited[2501] = {
        false,
    };
    for (vector<int> &row : grid) {
      for (int &num : row) {
        if (visited[num]) {
          duplicated = num;
        }
        visited[num] = true;
      }
    }

    for (int i = 1; i <= rows * cols; i++) {
      if (!visited[i]) {
        missed = i;
      }
    }
    return {duplicated, missed};
  }
};

// use math
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    long long sum = 0, sqrSum = 0;
    long long total = rows * cols;

    for (vector<int> &row : grid) {
      for (int &num : row) {
        sum += num;
        sqrSum += (long long)num * num;
      }
    }

    long long totalSum = total * (total + 1) / 2;
    long long totalSqrSum = total * (total + 1) * (2 * total + 1) / 6;

    long long sumDiff = sum - totalSum;
    long long sqrDiff = sqrSum - totalSqrSum;

    int duplicated = (sqrDiff / sumDiff + sumDiff) / 2;
    int missed = (sqrDiff / sumDiff - sumDiff) / 2;

    return {duplicated, missed};
  }
};