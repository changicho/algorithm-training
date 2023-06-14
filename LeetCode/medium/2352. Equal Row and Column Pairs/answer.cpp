#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use memorize row, col line
// time : O(N^3)
// space : O(N^2)
class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<int>> lineRows(rows), lineCols(cols);
    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        lineRows[y].push_back(grid[y][x]);
        lineCols[x].push_back(grid[y][x]);
      }
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (lineRows[y] == lineCols[x]) answer++;
      }
    }

    return answer;
  }
};

// use hash map
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    unordered_map<string, int> counts;
    int answer = 0;
    for (int y = 0; y < rows; y++) {
      string line = "";
      for (int x = 0; x < cols; x++) {
        line += to_string(grid[y][x]) + "/";
      }
      counts[line]++;
    }

    for (int x = 0; x < cols; x++) {
      string line = "";
      for (int y = 0; y < rows; y++) {
        line += to_string(grid[y][x]) + "/";
      }

      answer += counts[line];
    }

    return answer;
  }
};

// use map
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;
    map<vector<int>, int> count;

    for (vector<int>& row : grid) {
      count[row]++;
    }

    for (int x = 0; x < cols; x++) {
      vector<int> line;
      for (int y = 0; y < rows; y++) {
        line.push_back(grid[y][x]);
      }

      answer += count[line];
    }

    return answer;
  }
};