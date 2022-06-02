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
  bool sequenceReconstruction(vector<int>& nums,
                              vector<vector<int>>& sequences) {
    int size = nums.size();
    vector<int> inDegrees(size + 1, 0);
    vector<vector<int>> graph(size + 1);

    for (vector<int>& sequence : sequences) {
      int curSize = sequence.size();
      for (int i = 0; i < curSize - 1; i++) {
        int from = sequence[i], to = sequence[i + 1];

        graph[from].push_back(to);
        inDegrees[to]++;
      }
    }

    queue<int> q;
    for (int n = 1; n <= size; n++) {
      if (inDegrees[n] == 0) q.push(n);
    }

    if (q.size() > 1) return false;
    while (q.size() == 1) {
      int cur = q.front();
      q.pop();

      for (int& next : graph[cur]) {
        inDegrees[next]--;

        if (inDegrees[next] == 0) q.push(next);
      }
    }

    if (q.size() > 1) return false;

    return true;
  }
};