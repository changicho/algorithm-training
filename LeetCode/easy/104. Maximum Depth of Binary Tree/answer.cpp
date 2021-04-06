#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    return findLevel(root, 1);
  }

  int findLevel(TreeNode *root, int depth) {
    if (!root) return depth - 1;

    return max(findLevel(root->left, depth + 1), findLevel(root->right, depth + 1));
  }
};

// BFS

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    queue<TreeNode *> q;

    q.push(root);
    int depth = 0;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *cur = q.front();
        q.pop();

        if (!cur) continue;
        q.push(cur->left);
        q.push(cur->right);
      }

      depth += 1;
    }

    return depth - 1;
  }
};