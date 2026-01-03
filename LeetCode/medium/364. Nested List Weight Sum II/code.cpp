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

class NestedInteger {
 public:
  NestedInteger();
  NestedInteger(int value);
  bool isInteger() const;
  int getInteger() const;
  void setInteger(int value);
  void add(const NestedInteger& ni);
  vector<NestedInteger> getList() const;
};

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int maxDepth = 0;

    queue<NestedInteger> q;
    for (NestedInteger& ni : nestedList) {
      q.push(ni);
    }
    int depth = 1;
    int count = 0;

    // num, depth;
    vector<pair<int, int>> vals;
    while (!q.empty()) {
      int size = q.size();
      maxDepth = depth;

      while (size--) {
        NestedInteger cur = q.front();
        q.pop();

        if (cur.isInteger()) {
          vals.push_back({cur.getInteger(), depth});
          continue;
        }

        for (NestedInteger& next : cur.getList()) {
          q.push(next);
        }
      }
      depth++;
    }

    int answer = 0;
    for (pair<int, int>& cur : vals) {
      answer += cur.first * (maxDepth - cur.second + 1);
    }
    return answer;
  }
};