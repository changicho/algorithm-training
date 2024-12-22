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

// use DFS
// time : O(V + E)
// space : O(V + E)
class Solution {
 public:
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    vector<vector<int>> graph(n);
    for (vector<int> &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int answer = 0;

    function<int(int, int)> recursive = [&](int cur, int parent) {
      int sum = 0;

      for (int &next : graph[cur]) {
        if (next == parent) continue;

        sum += recursive(next, cur);
        sum %= k;
      }

      sum += values[cur];
      sum %= k;

      if (sum == 0) answer++;
      return sum;
    };

    recursive(0, -1);

    return answer;
  }
};