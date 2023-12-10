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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use preorder
// time : O(N)
// space : O(N)
class Solution {
 private:
  string ret = "";

  void recursive(TreeNode *node) {
    ret += to_string(node->val);

    if (!node->left && !node->right) return;

    if (node->left) {
      ret += '(';
      recursive(node->left);
      ret += ')';
    }
    if (node->right) {
      if (!node->left) {
        ret += "()";
      }
      ret += '(';
      recursive(node->right);
      ret += ')';
    }
  }

 public:
  string tree2str(TreeNode *root) {
    if (root) recursive(root);
    return ret;
  }
};