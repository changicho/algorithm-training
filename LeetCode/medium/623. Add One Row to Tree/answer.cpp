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

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, NULL);
    }

    if (depth == 2) {
      root->left = new TreeNode(val, root->left, NULL);
      root->right = new TreeNode(val, NULL, root->right);
      return root;
    }

    if (root->left) {
      root->left = addOneRow(root->left, val, depth - 1);
    }
    if (root->right) {
      root->right = addOneRow(root->right, val, depth - 1);
    }
    return root;
  }
};