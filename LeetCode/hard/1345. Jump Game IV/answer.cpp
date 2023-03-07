#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int size = arr.size();

    unordered_map<int, vector<int>> indexes;

    for (int i = 0; i < size; i++) {
      indexes[arr[i]].push_back(i);
    }

    vector<int> dp(size, INT_MAX);

    queue<int> q;
    q.push(0);

    int step = 0;
    while (!q.empty()) {
      int curSize = q.size();

      while (curSize--) {
        int cur = q.front();
        q.pop();

        if (dp[cur] <= step) continue;
        dp[cur] = step;

        if (cur - 1 >= 0 && dp[cur - 1] > step + 1) {
          q.push(cur - 1);
        }
        if (cur + 1 < size && dp[cur + 1] > step + 1) {
          q.push(cur + 1);
        }

        for (int next : indexes[arr[cur]]) {
          if (dp[next] <= step + 1) continue;
          q.push(next);
        }

        indexes[arr[cur]].clear();
      }
      step++;
    }

    return dp[size - 1];
  }
};