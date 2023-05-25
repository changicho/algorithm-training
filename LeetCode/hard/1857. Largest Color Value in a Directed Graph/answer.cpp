#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use topological sort
// time : O(N + E)
// space : O(N + E)
class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int size = colors.size();
    vector<vector<int>> graph(size);
    vector<int> inDegree(size);

    for (vector<int>& edge : edges) {
      int from = edge[0], to = edge[1];
      graph[from].push_back(to);
      inDegree[to]++;
    }

    vector<vector<int>> counts(size, vector<int>(26, 0));
    queue<int> q;

    for (int node = 0; node < size; node++) {
      if (inDegree[node] == 0) {
        q.push(node);
      }
    }

    int answer = 0, nodesSeen = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      // increase current color
      int curColor = colors[cur] - 'a';
      counts[cur][curColor]++;
      answer = max(answer, counts[cur][curColor]);
      nodesSeen++;

      for (int& next : graph[cur]) {
        for (int color = 0; color < 26; color++) {
          counts[next][color] = max(counts[next][color], counts[cur][color]);
        }

        inDegree[next]--;
        if (inDegree[next] == 0) {
          q.push(next);
        }
      }
    }

    return nodesSeen < size ? -1 : answer;
  }
};