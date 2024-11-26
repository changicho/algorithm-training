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

// use BFS
// time : O(6! * 6)
// space : O(6!)
class Solution {
 private:
  string convert(vector<vector<int>> &board) {
    string ret = "";
    for (vector<int> &line : board) {
      for (int &num : line) {
        ret += (num + '0');
      }
    }
    return ret;
  }

 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    // 0 1 2
    // 3 4 5
    vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5},
                                {0, 4}, {1, 3, 5}, {2, 4}};

    string target = "123450";
    string start = convert(board);

    unordered_set<string> visited;
    queue<string> q;
    visited.insert(start);
    q.push(start);

    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        string cur = q.front();
        q.pop();

        if (cur == target) {
          return step;
        }

        int zeroI = cur.find('0');

        for (int &dir : dirs[zeroI]) {
          string next = cur;
          swap(next[zeroI], next[dir]);

          if (visited.count(next)) continue;
          visited.insert(next);
          q.push(next);
        }
      }

      step++;
    }
    return -1;
  }
};