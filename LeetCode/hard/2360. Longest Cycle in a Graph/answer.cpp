#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use topological sort
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    int size = edges.size();
    vector<bool> visit(size);
    vector<int> inDegrees(size);

    for (int edge : edges) {
      if (edge != -1) {
        inDegrees[edge]++;
      }
    }

    queue<int> q;
    for (int node = 0; node < size; node++) {
      if (inDegrees[node] == 0) {
        q.push(node);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      visit[node] = true;
      int neighbor = edges[node];
      if (neighbor != -1) {
        inDegrees[neighbor]--;
        if (inDegrees[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    int answer = -1;
    for (int node = 0; node < size; node++) {
      if (!visit[node]) {
        int next = edges[node];
        int length = 1;
        visit[node] = true;

        while (next != node) {
          visit[next] = true;
          length++;
          next = edges[next];
        }
        answer = max(answer, length);
      }
    }

    return answer;
  }
};