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

// use recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  int recursive(int node, int parent, vector<vector<int>> &graph) {
    int ret = 0;

    int children = -1;
    bool isGood = true;
    for (int &next : graph[node]) {
      if (next == parent) continue;

      int result = recursive(next, node, graph);

      ret += result;
      if (children == -1) {
        children = result;
      } else if (children != result) {
        isGood = false;
      }
    }

    if (isGood) answer++;
    ret += 1;
    return ret;
  }

 public:
  int countGoodNodes(vector<vector<int>> &edges) {
    int size = edges.size() + 1;

    vector<vector<int>> graph(size);

    for (vector<int> &e : edges) {
      int from = e[0], to = e[1];
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    recursive(0, -1, graph);

    return answer;
  }
};