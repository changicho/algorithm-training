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

using ll = long long;

// stack
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Data {
    int t, c, count;
  };

 public:
  bool canRemoveAll(vector<int>& types, vector<int>& colors,
                    vector<int>& groupSize) {
    int size = types.size();

    vector<Data> stk;
    for (int i = 0; i < size; i++) {
      int t = types[i], c = colors[i];

      if (!stk.empty() && stk.back().t == t && stk.back().c == c) {
        stk.back().count++;
      } else {
        stk.push_back({t, c, 1});
      }

      if (stk.back().count == groupSize[t]) {
        stk.pop_back();
      }
    }

    if (stk.size() > 0) return false;

    return true;
  }
};