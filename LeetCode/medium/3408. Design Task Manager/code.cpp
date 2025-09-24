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

// use heap with hash map
// time : O(N * log_2(N))
// space : O(N)
class TaskManager {
 private:
  unordered_map<int, pair<int, int>> um;
  priority_queue<pair<int, int>> pq;

 public:
  TaskManager(vector<vector<int>>& tasks) {
    for (vector<int>& t : tasks) {
      // [userId, taskId, priority
      int userId = t[0], taskId = t[1], priority = t[2];
      um[taskId] = {priority, userId};
      pq.emplace(priority, taskId);
    }
  }

  void add(int userId, int taskId, int priority) {
    um[taskId] = {priority, userId};
    pq.emplace(priority, taskId);
  }

  void edit(int taskId, int newPriority) {
    um[taskId].first = newPriority;
    pq.emplace(newPriority, taskId);
  }

  void rmv(int taskId) { um[taskId].first = -1; }

  int execTop() {
    while (!pq.empty()) {
      auto [priority, taskId] = pq.top();
      if (um.count(taskId) && um[taskId].first == priority) {
        pq.pop();
        int userId = um[taskId].second;
        um.erase(taskId);
        return userId;
      }
      pq.pop();
    }
    return -1;
  }
};