#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                          vector<vector<int>>& series2) {
    int size1 = series1.size(), size2 = series2.size();
    vector<vector<int>> answer;

    int i1 = 0, i2 = 0;

    while (i1 < size1 && i2 < size2) {
      int time = min(series1[i1][0], series2[i2][0]);
      int val1 = series1[i1][1];
      int val2 = series2[i2][1];

      int val = val1 + val2;

      answer.push_back({time, val});

      if (series1[i1][0] == time) {
        i1++;
      }
      if (series2[i2][0] == time) {
        i2++;
      }
    }

    while (i1 < size1) {
      answer.push_back(series1[i1]);
      i1++;
    }
    while (i2 < size2) {
      answer.push_back(series2[i2]);
      i2++;
    }

    return answer;
  }
};