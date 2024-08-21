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

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 private:
  int getCount(vector<int> &line) {
    int size = line.size();

    vector<int> remains;
    vector<int> empties;
    for (int i = 0; i < size; i++) {
      while (line[i] > 1) {
        remains.push_back(i);
        line[i]--;
      }
      if (line[i] == 0) {
        empties.push_back(i);
      }
    }

    int ret = 0;
    for (int i = 0; i < empties.size(); i++) {
      int diff = abs(remains[i] - empties[i]);
      ret += diff;
    }
    return ret;
  }

 public:
  int minMoves(vector<vector<int>> &rooks) {
    int rows = rooks.size(), cols = rooks.size();

    vector<int> rowCounts(rows, 0);
    vector<int> colCounts(cols, 0);

    for (vector<int> &rook : rooks) {
      int y = rook[0], x = rook[1];

      rowCounts[y]++;
      colCounts[x]++;
    }

    int answer = getCount(rowCounts) + getCount(colCounts);
    return answer;
  }
};

// use greedy (counting)
// time : O(N)
// space : O(N)
class Solution {
 private:
  int getCount(vector<int> &line) {
    int size = line.size();

    int diff = 0;
    int ret = 0;
    for (int i = 0; i < size; i++) {
      diff += line[i] - 1;
      ret += abs(diff);
    }
    return ret;
  }

 public:
  int minMoves(vector<vector<int>> &rooks) {
    int rows = rooks.size(), cols = rooks.size();

    vector<int> rowCounts(rows, 0);
    vector<int> colCounts(cols, 0);

    for (vector<int> &rook : rooks) {
      int y = rook[0], x = rook[1];

      rowCounts[y]++;
      colCounts[x]++;
    }

    int answer = getCount(rowCounts) + getCount(colCounts);
    return answer;
  }
};