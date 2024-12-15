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

// use in degree
// time : O(N + E)
// space : O(N)
class Solution {
 public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> inDegrees(n, 0);

    for (vector<int>& e : edges) {
      int from = e[0], to = e[1];

      inDegrees[to]++;
    }

    int answer = -1;
    for (int i = 0; i < n; i++) {
      if (inDegrees[i] == 0) {
        if (answer != -1) return -1;
        answer = i;
      }
    }
    return answer;
  }
};