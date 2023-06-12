#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int size = 0;
  int answer = 0;
  vector<vector<int>> children;
  vector<int> informTime;

  void recursive(int node, int time) {
    answer = max(answer, time);

    for (int& next : children[node]) {
      recursive(next, time + informTime[node]);
    }
  }

 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    this->size = n;
    this->informTime = informTime;

    children.resize(n);

    for (int i = 0; i < n; i++) {
      if (manager[i] == -1) continue;
      children[manager[i]].push_back(i);
    }

    recursive(headID, 0);
    return answer;
  }
};