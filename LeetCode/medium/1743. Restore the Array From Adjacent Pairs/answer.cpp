#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, vector<int>> graph;

    for (vector<int> &pair : adjacentPairs) {
      int from = pair[0], to = pair[1];

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    int cur = -1;
    unordered_set<int> visited;

    for (auto it : graph) {
      if (it.second.size() == 1) {
        cur = it.first;
        break;
      }
    }

    vector<int> answer;
    while (visited.count(cur) == 0) {
      answer.push_back(cur);
      visited.insert(cur);

      for (int &next : graph[cur]) {
        if (visited.count(next) > 0) continue;

        cur = next;
        break;
      }
    }

    return answer;
  }
};