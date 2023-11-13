#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2 * M)
// time : O(N * M)
class Solution {
 public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> graph;
    for (int index = 0; index < routes.size(); index++) {
      for (int &stop : routes[index]) {
        graph[stop].push_back(index);
      }
    }

    queue<int> q;
    unordered_set<int> visited;
    for (int &route : graph[source]) {
      q.push(route);
      visited.insert(route);
    }

    int busCount = 1;
    while (q.size()) {
      int size = q.size();

      while (size--) {
        int cur = q.front();
        q.pop();

        for (int &stop : routes[cur]) {
          if (stop == target) {
            return busCount;
          }

          for (int &next : graph[stop]) {
            if (visited.count(next)) continue;

            visited.insert(next);
            q.push(next);
          }
        }
      }
      busCount++;
    }
    return -1;
  }
};