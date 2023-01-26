#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> getDistances(int startNode, vector<int>& edges) {
    int size = edges.size();
    vector<int> dist(size, INT_MAX);
    vector<bool> visit(size, false);

    queue<int> q;
    q.push(startNode);
    dist[startNode] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      if (visit[node]) {
        continue;
      }

      visit[node] = true;
      int neighbor = edges[node];
      if (neighbor != -1 && !visit[neighbor]) {
        dist[neighbor] = 1 + dist[node];
        q.push(neighbor);
      }
    }
    return dist;
  }

 public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int size = edges.size();
    vector<int> dist1 = getDistances(node1, edges),
                dist2 = getDistances(node2, edges);

    int target = -1, minDist = INT_MAX;
    for (int node = 0; node < size; node++) {
      if (minDist > max(dist1[node], dist2[node])) {
        target = node;
        minDist = max(dist1[node], dist2[node]);
      }
    }

    return target;
  }
};