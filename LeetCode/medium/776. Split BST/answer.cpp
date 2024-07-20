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
  vector<TreeNode *> splitBST(TreeNode *root, int target) {
    if (!root) {
      return {NULL, NULL};
    }

    if (root->val > target) {
      vector<TreeNode *> left = splitBST(root->left, target);

      root->left = left[1];
      return {left[0], root};
    } else {
      vector<TreeNode *> right = splitBST(root->right, target);

      root->right = right[0];
      return {root, right[1]};
    }
  }
};