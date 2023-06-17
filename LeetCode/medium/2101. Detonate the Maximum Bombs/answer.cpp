#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  vector<vector<int>> graph;

  // can reach a to b
  bool isAssociate(vector<int> &a, vector<int> &b) {
    long long xDiff = abs(a[0] - b[0]);
    long long yDiff = abs(a[1] - b[1]);
    long long r = a[2];

    long long length = xDiff * xDiff + yDiff * yDiff;

    return length <= (r * r);
  }

  int calcDetonatedBombs(int node) {
    int size = graph.size();
    vector<bool> visited(size, false);
    int count = 0;
    queue<int> q;

    q.push(node);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;
      count++;

      for (int &next : graph[cur]) {
        q.push(next);
      }
    }
    return count;
  }

 public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int size = bombs.size();

    graph.resize(size);

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i == j) continue;
        if (isAssociate(bombs[i], bombs[j])) {
          graph[i].push_back(j);
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int count = calcDetonatedBombs(i);
      answer = max(answer, count);
    }
    return answer;
  }
};