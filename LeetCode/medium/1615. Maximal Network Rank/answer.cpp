#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2 + E)
// space : O(E)
class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<unordered_set<int>> graph(n);

    for (vector<int>& e : roads) {
      int from = e[0], to = e[1];

      graph[from].insert(to);
      graph[to].insert(from);
    }

    int answer = 0;
    for (int node = 0; node < n; node++) {
      for (int next = node + 1; next < n; next++) {

        int count = graph[node].size() + graph[next].size();

        if (graph[node].count(next)) count--;

        answer = max(answer, count);
      }
    }
    return answer;
  }
};