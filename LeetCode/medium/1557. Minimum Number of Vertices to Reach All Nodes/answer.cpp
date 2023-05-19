#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use in degree
// time : O(V + E)
// space : O(V)
class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    int inDegree[100001] = {
        0,
    };

    for (vector<int>& e : edges) {
      int from = e[0], to = e[1];

      inDegree[to]++;
    }

    vector<int> answer;
    for (int node = 0; node < n; node++) {
      if (inDegree[node] == 0) {
        answer.push_back(node);
      }
    }

    return answer;
  }
};