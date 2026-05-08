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

// disjoint set (union find)
// time : O(N + M)
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
  int minimumHammingDistance(vector<int>& source, vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    int size = source.size();
    parents.resize(size);
    for (int i = 0; i < size; i++) {
      parents[i] = i;
    }

    for (vector<int>& e : allowedSwaps) {
      merge(e[0], e[1]);
    }

    vector<vector<int>> groups(size);
    for (int i = 0; i < size; i++) {
      groups[find(i)].push_back(i);
    }
    int answer = 0;
    for (int p = 0; p < size; p++) {
      unordered_map<int, int> count;
      for (int& i : groups[p]) {
        count[source[i]]++;
        count[target[i]]--;
      }

      int diff = 0;
      for (auto [key, val] : count) {
        diff += abs(val);
      }

      answer += diff / 2;
    }
    return answer;
  }
};