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

// DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  unordered_map<int, vector<int>> children;

  vector<int> answer;

  void dfs(int node, bool isKill, int kill) {
    if (kill == node) {
      isKill = true;
    }
    if (isKill) answer.push_back(node);

    for (int& next : children[node]) {
      dfs(next, isKill, kill);
    }
  }

 public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    int size = pid.size();

    int start = -1;
    for (int i = 0; i < size; i++) {
      int c = pid[i];
      int p = ppid[i];

      if (p == 0) {
        start = c;
      } else {
        children[p].push_back(c);
      }
    }

    dfs(start, false, kill);
    return answer;
  }
};