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
  bool evaluateTree(TreeNode *root) {
    if (!root->left && !root->right) {
      // leaf case

      return root->val;
    }

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    if (root->val == 2) {
      return left || right;
    } else {
      return left && right;
    }
  }
};