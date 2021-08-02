#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use recursive

class Solution {
 private:
  TreeNode* subRoot = NULL;

  void recursive(TreeNode* node) {
    if (!node->left && !subRoot) {
      subRoot = node;
    }

    if (!node->left && !node->right) return;

    if (node->left) recursive(node->left);

    TreeNode* left = node->left;
    TreeNode* right = node->right;

    left->right = node;
    left->left = right;

    node->left = node->right = NULL;
  }

 public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root) recursive(root);

    return subRoot;
  }
};

// use iterate

class Solution {
 public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    TreeNode* cur = root;

    TreeNode *parent = NULL, *right = NULL, *next = NULL;

    while (cur) {
      next = cur->left;

      cur->left = right;
      right = cur->right;
      cur->right = parent;
      parent = cur;

      cur = next;
    }
    return parent;
  }
};