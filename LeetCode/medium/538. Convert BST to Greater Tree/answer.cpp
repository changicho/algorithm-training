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

// use recursive
// time : O(N)
// space : O(H)
class Solution {
 private:
  int before = 0;

  void recursive(TreeNode *node) {
    if (node->right) recursive(node->right);

    node->val += before;
    before = node->val;

    if (node->left) recursive(node->left);
  }

 public:
  TreeNode *convertBST(TreeNode *root) {
    if (!root) return NULL;

    recursive(root);

    return root;
  }
};