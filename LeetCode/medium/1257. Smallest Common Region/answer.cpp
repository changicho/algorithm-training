#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use parent path
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  string findSmallestRegion(vector<vector<string>>& regions, string region1,
                            string region2) {
    unordered_map<string, string> parents;

    for (vector<string>& r : regions) {
      string p = r[0];

      for (int i = 1; i < r.size(); i++) {
        string c = r[i];
        parents[c] = p;
      }
    }

    unordered_set<string> visited;
    string cur = region1;
    visited.insert(cur);
    while (parents.count(cur)) {
      cur = parents[cur];
      visited.insert(cur);
    }

    cur = region2;
    if (visited.count(cur)) return cur;
    while (parents.count(cur)) {
      cur = parents[cur];
      if (visited.count(cur)) return cur;
    }
    return "";
  }
};