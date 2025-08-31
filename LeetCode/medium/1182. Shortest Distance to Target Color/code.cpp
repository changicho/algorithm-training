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

// use binary search
// time : O(Q * log_2(N) + N)
// space : O(N + Q)
class Solution {
 public:
  vector<int> shortestDistanceColor(vector<int>& colors,
                                    vector<vector<int>>& queries) {
    vector<int> indexes[3];

    int size = colors.size();
    for (int i = 0; i < size; i++) {
      int c = colors[i] - 1;
      indexes[c].push_back(i);
    }

    vector<int> answer;
    for (vector<int>& q : queries) {
      int i = q[0], c = q[1] - 1;

      vector<int>& arr = indexes[c];

      int lower = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
      int high = upper_bound(arr.begin(), arr.end(), i) - arr.begin() - 1;

      int target = INT_MAX;
      if (lower >= 0 && lower < arr.size()) {
        target = min(target, abs(arr[lower] - i));
      }

      if (high >= 0 && high < arr.size()) {
        target = min(target, abs(arr[high] - i));
      }
      answer.push_back(target == INT_MAX ? -1 : target);
    }
    return answer;
  }
};

// use pre calculation
// time : O(N + Q)
// space : O(N + Q)
class Solution {
 public:
  vector<int> shortestDistanceColor(vector<int>& colors,
                                    vector<vector<int>>& queries) {
    int size = colors.size();
    int lefts[3] = {0, 0, 0};
    int rights[3] = {size - 1, size - 1, size - 1};

    vector<vector<int>> dists(size, vector<int>(3, INT_MAX));

    for (int i = 0; i < size; i++) {
      int rI = size - 1 - i;

      int c = colors[i] - 1;

      for (int before = lefts[c]; before <= i; before++) {
        dists[before][c] = min(dists[before][c], i - before);
      }
      lefts[c] = i + 1;

      int rc = colors[rI] - 1;

      for (int before = rights[rc]; before >= rI; before--) {
        dists[before][rc] = min(dists[before][rc], before - rI);
      }
      rights[rc] = rI - 1;
    }

    vector<int> answer;

    for (vector<int>& q : queries) {
      int i = q[0], c = q[1] - 1;

      int d = dists[i][c];

      answer.push_back(d == INT_MAX ? -1 : d);
    }

    return answer;
  }
};