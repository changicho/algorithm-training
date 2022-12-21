#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int size = rooms.size();

    unordered_set<int> visited;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (visited.count(cur)) continue;
      visited.insert(cur);

      for (int next : rooms[cur]) {
        q.push(next);
      }
    }

    return visited.size() == size;
  }
};