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

// use greedy with hash set
// time : O(N + M + E)
// space : O(N + M)
class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    unordered_set<int> needs;

    for (vector<int> &e : friendships) {
      int a = e[0] - 1, b = e[1] - 1;

      bool hasSame = false;
      unordered_set<int> visited;
      for (int &l : languages[a]) {
        visited.insert(l);
      }
      for (int &l : languages[b]) {
        if (visited.count(l)) {
          hasSame = true;
          break;
        }
      }
      if (!hasSame) {
        needs.insert(a);
        needs.insert(b);
      }
    }

    int maxCount = 0;
    vector<int> count(n + 1, 0);
    for (int p : needs) {
      for (int &l : languages[p]) {
        count[l]++;
        maxCount = max(maxCount, count[l]);
      }
    }
    return needs.size() - maxCount;
  }
};