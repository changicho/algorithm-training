#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count inDegree
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> inDegrees(n + 1);

    for (vector<int>& edge : edges) {
      inDegrees[edge[0]]++;
      inDegrees[edge[1]]++;

      if (inDegrees[edge[0]] == n - 1) return edge[0];
      if (inDegrees[edge[1]] == n - 1) return edge[1];
    }

    return -1;
  }
};