#include <algorithm>
#include <iostream>
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

// use DFS

class Solution {
 public:
  TreeNode *pruneTree(TreeNode *root) {
    bool hasOne = false;
    if (root) hasOne = recursive(root);
    if (!hasOne) return NULL;

    return root;
  }

  bool recursive(TreeNode *node) {
    bool hasOne = false;
    if (node->val == 1) hasOne = true;

    if (node->left) {
      bool hasLeftOne = recursive(node->left);

      if (!hasLeftOne) {
        node->left = NULL;
      } else {
        hasOne = true;
      }
    }

    if (node->right) {
      bool hasRightOne = recursive(node->right);

      if (!hasRightOne) {
        node->right = NULL;
      } else {
        hasOne = true;
      }
    }

    return hasOne;
  }
};
