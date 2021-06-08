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

// use recursive inOrder

class Solution {
 public:
  TreeNode *pre = new TreeNode();
  void flatten(TreeNode *root) {
    recursive(root);
  }

  void recursive(TreeNode *node) {
    if (!node) return;

    pre->right = node;
    pre = pre->right;

    TreeNode *left = node->left, *right = node->right;

    recursive(left);
    recursive(right);

    node->left = NULL;
  }
};

// use while inOrder

class Solution {
 public:
  void flatten(TreeNode *root) {
    TreeNode *cur = root;

    while (cur) {
      if (cur->left) {
        TreeNode *pre = cur->left;
        while (pre->right) {
          pre = pre->right;
        }

        pre->right = cur->right;
        cur->right = cur->left;
        cur->left = NULL;
      }
      cur = cur->right;
    }
  }
};