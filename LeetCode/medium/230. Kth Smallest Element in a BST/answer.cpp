#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use inorder
// time : O(K)
// space : O(K)
class Solution {
 private:
  void recursive(TreeNode* node, vector<int>& vals, int& k) {
    if (vals.size() == k) return;
    if (node->left) recursive(node->left, vals, k);
    vals.push_back(node->val);
    if (node->right) recursive(node->right, vals, k);
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> vals;
    if (root) recursive(root, vals, k);

    return vals[k - 1];
  }
};