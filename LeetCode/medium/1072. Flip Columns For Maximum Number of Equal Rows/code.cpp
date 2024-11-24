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

// use hash map
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  string convert(vector<int>& row) {
    string ret = "";
    int first = row[0];
    for (int& i : row) {
      ret += first == i ? '0' : '1';
    }
    return ret;
  }

 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> count;

    for (vector<int>& row : matrix) {
      string line = convert(row);

      count[line]++;
    }

    int answer = 0;
    for (auto& cur : count) {
      answer = max(cur.second, answer);
    }

    return answer;
  }
};