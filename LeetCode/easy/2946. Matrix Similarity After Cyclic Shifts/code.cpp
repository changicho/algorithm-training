#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// one pass
// time : O(RC)
// space : O(1)
class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int rows = mat.size(), cols = mat[0].size();

    k %= cols;

    for (vector<int>& row : mat) {
      for (int x = 0; x < cols; x++) {
        if (row[x] != row[(x + k) % cols]) return false;
      }
    }
    return true;
  }
};