#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use disjoin set
// time : O(V + E)
// space : O(V)
class Solution {
 private:
  struct UnionFind {
    vector<int> parents;
    int unique = 0;

    UnionFind(int size) {
      parents.resize(size + 1);
      for (int i = 1; i <= size; i++) {
        parents[i] = i;
      }
      unique = size;
    }

    int find(int node) {
      if (parents[node] == node) return node;
      return parents[node] = find(parents[node]);
    }

    bool merge(int a, int b) {
      a = find(a), b = find(b);
      if (a == b) return false;
      unique--;

      if (a > b) swap(a, b);
      parents[b] = a;
      return true;
    }
  };

 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UnionFind alice(n), bob(n);

    int required = 0;
    for (vector<int>& e : edges) {
      int type = e[0], a = e[1], b = e[2];
      if (type == 3) {
        required += (alice.merge(a, b) | bob.merge(a, b));
      }
    }

    for (vector<int>& e : edges) {
      int type = e[0], a = e[1], b = e[2];
      if (type == 1) {
        required += alice.merge(a, b);
      } else if (type == 2) {
        required += bob.merge(a, b);
      }
    }

    if (alice.unique > 1 || bob.unique > 1) return -1;
    return edges.size() - required;
  }
};