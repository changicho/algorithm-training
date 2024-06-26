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

// use recursive (RDL)
// time : O(N)
// space : O(N)
class Solution {
 private:
  int sum = 0;

  void recursive(TreeNode *node) {
    if (!node) return;
    recursive(node->right);

    int val = node->val;
    node->val += sum;
    sum += val;

    recursive(node->left);
  }

 public:
  TreeNode *bstToGst(TreeNode *root) {
    recursive(root);

    return root;
  }
};