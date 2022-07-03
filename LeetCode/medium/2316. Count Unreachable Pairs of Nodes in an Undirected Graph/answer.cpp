#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use disjoint set
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];
      merge(a, b);
    }

    long long answer = 0;
    unordered_map<int, int> counts;
    for (int node = 0; node < n; node++) {
      counts[find(node)]++;
    }

    for (auto &it : counts) {
      int key = it.first, val = it.second;

      answer += (long long)val * (n - val);
    }
    return answer / 2;
  }
};