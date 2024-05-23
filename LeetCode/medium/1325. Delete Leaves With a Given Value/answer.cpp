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
// space : O(N)
class Solution {
 public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (!root) return NULL;

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // leaf case
    if (!root->left && !root->right) {
      if (root->val == target) return NULL;
      return root;
    }

    return root;
  }
};
