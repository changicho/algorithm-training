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

// use recursive

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    recursive(root);
    return root;
  }

  void recursive(TreeNode *node) {
    if (!node) return;

    swap(node->left, node->right);

    recursive(node->left);
    recursive(node->right);
  }
};

// use queue

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();

      if (!cur) continue;

      swap(cur->left, cur->right);

      q.push(cur->left);
      q.push(cur->right);
    }

    return root;
  }
};