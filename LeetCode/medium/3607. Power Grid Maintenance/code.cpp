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

// use union find & BST set
// time : O(E + (C + Q) \* log_2(C))
// space : O(C + Q)
class Solution {
 private:
  vector<int> parents;

  int find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find(parents[a]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  vector<int> processQueries(int c, vector<vector<int>>& connections,
                             vector<vector<int>>& queries) {
    vector<int> answer;

    parents.resize(c + 1);
    for (int i = 1; i <= c; i++) {
      parents[i] = i;
    }
    for (vector<int>& e : connections) {
      int a = e[0], b = e[1];

      merge(a, b);
    }

    vector<set<int>> onLines(c + 1);
    for (int i = 1; i <= c; i++) {
      int p = find(i);

      onLines[p].insert(i);
    }

    for (vector<int>& q : queries) {
      int type = q[0], target = q[1];

      int p = find(target);
      if (type == 1) {
        if (onLines[p].size() == 0) {
          answer.push_back(-1);
          continue;
        }
        if (onLines[p].count(target)) {
          answer.push_back(target);
          continue;
        }
        answer.push_back(*onLines[p].begin());
      } else {
        onLines[p].erase(target);
      }
    }

    return answer;
  }
};

// use union find & reverse query
// time : O(E + C + Q)
// space : O(C + Q)
class Solution {
 private:
  vector<int> parents;

  int find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find(parents[a]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  vector<int> processQueries(int c, vector<vector<int>>& connections,
                             vector<vector<int>>& queries) {
    vector<int> answer;

    parents.resize(c + 1);
    for (int i = 1; i <= c; i++) {
      parents[i] = i;
    }
    for (vector<int>& e : connections) {
      int a = e[0], b = e[1];

      merge(a, b);
    }

    vector<int> delCount(c + 1, 0);
    vector<int> minByParent(c + 1, INT_MAX);
    for (vector<int>& q : queries) {
      int type = q[0], target = q[1];

      if (type == 2) {
        delCount[target]++;
      }
    }
    for (int i = 1; i <= c; i++) {
      if (delCount[i] == 0) {
        int p = find(i);
        minByParent[p] = min(minByParent[p], i);
      }
    }

    for (int i = queries.size() - 1; i >= 0; i--) {
      vector<int>& q = queries[i];
      int type = q[0], target = q[1];

      int p = find(target);
      if (type == 1) {
        if (delCount[target] == 0) {
          answer.push_back(target);
        } else if (minByParent[p] == INT_MAX) {
          answer.push_back(-1);
        } else {
          answer.push_back(minByParent[p]);
        }
      } else {
        delCount[target]--;

        if (delCount[target] == 0) {
          minByParent[p] = min(minByParent[p], target);
        }
      }
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};