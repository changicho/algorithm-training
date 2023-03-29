#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use union find
// time : O(N + E)
// space : O(N)
class Solution {
 private:
  vector<int> parents;
  int parentsCount = 0;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
    parentsCount--;
  }

 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    parentsCount = n;

    for (vector<int>& c : connections) {
      int a = c[0], b = c[1];

      merge(a, b);
    }

    return parentsCount - 1;
  }
};