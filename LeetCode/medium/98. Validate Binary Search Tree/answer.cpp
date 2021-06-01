#include <algorithm>
#include <iostream>
#include <stack>
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

// use recursive with value

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return recursive(root, LONG_MIN, LONG_MAX);
  }

  bool recursive(TreeNode *root, long min, long max) {
    if (!root) return true;
    if (root->val <= min) return false;
    if (root->val >= max) return false;

    return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
  }
};

// use recursive with node

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return recursive(root, NULL, NULL);
  }

  bool recursive(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
    if (!root) return true;
    if (minNode && root->val <= minNode->val) return false;
    if (maxNode && root->val >= maxNode->val) return false;

    return recursive(root->left, minNode, root) && recursive(root->right, root, maxNode);
  }
};

// use stack

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    long pre = LONG_MIN;
    stack<TreeNode *> s;

    while (root || !s.empty()) {
      while (root) {
        s.push(root);
        root = root->left;
      }
      root = s.top();
      s.pop();

      if (root->val <= pre) {
        return false;
      }

      pre = root->val;
      root = root->right;
    }

    return true;
  }
};