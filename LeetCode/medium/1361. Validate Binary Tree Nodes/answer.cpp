#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool visited[10001] = {
      false,
  };

  bool hasCycle = false;

  int findRoot(int n, vector<int>& left, vector<int>& right) {
    unordered_set<int> children;
    children.insert(left.begin(), left.end());
    children.insert(right.begin(), right.end());

    int ret = -1;
    for (int node = 0; node < n; node++) {
      if (children.count(node) == 0) {
        if (ret != -1) return -1;
        ret = node;
      }
    }

    return ret;
  }

  void recursive(int node, vector<int>& leftChild, vector<int>& rightChild) {
    if (hasCycle) return;

    int children[] = {leftChild[node], rightChild[node]};
    for (int& child : children) {
      if (child == -1) continue;

      if (visited[child]) {
        hasCycle = true;
        return;
      }

      visited[child] = true;
      recursive(child, leftChild, rightChild);
    }
  }

 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    int root = findRoot(n, leftChild, rightChild);
    if (root == -1) return false;

    visited[root] = true;

    recursive(root, leftChild, rightChild);
    int count = 0;
    for (int node = 0; node < n; node++) {
      count += visited[node];
    }
    return !hasCycle && count == n;
  }
};