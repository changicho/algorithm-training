#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use union find
// time : O(N * sqrt(M))
// space : O(N)
class Solution {
 private:
  vector<int> parents;
  vector<int> children;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return;
    }

    if (children[a] < children[b]) {
      swap(a, b);
    }
    parents[b] = a;
    children[a] += children[b];
  }

 public:
  bool canTraverseAllPairs(vector<int> &nums) {
    int size = nums.size();
    if (size == 1) return true;

    parents.resize(size);
    children.resize(size, 1);
    for (int node = 0; node < size; node++) {
      parents[node] = node;
    }

    unordered_map<int, int> divisor2targets;
    for (int node = 0; node < size; node++) {
      int cur = nums[node];
      if (cur == 1) return false;

      for (int d = 2; d * d <= cur; d++) {
        if (cur % d != 0) continue;

        if (divisor2targets.count(d)) {
          int target = divisor2targets[d];
          merge(node, target);
        } else {
          divisor2targets[d] = node;
        }

        while (cur % d == 0) {
          cur /= d;
        }
      }

      if (cur == 1) continue;
      if (divisor2targets.count(cur)) {
        merge(node, divisor2targets[cur]);
      } else {
        divisor2targets[cur] = node;
      }
    }

    return children[find(0)] == size;
  }
};
