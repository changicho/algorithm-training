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

// use inOrder & recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  void getVals(TreeNode *node, vector<int> &vals) {
    if (!node) return;

    getVals(node->left, vals);
    vals.push_back(node->val);
    getVals(node->right, vals);
  }

  TreeNode *recursive(int left, int right, vector<int> &vals) {
    if (left > right) return NULL;
    if (left == right) {
      return new TreeNode(vals[left]);
    }

    int mid = left + (right - left) / 2;

    TreeNode *node = new TreeNode(vals[mid]);
    node->left = recursive(left, mid - 1, vals);
    node->right = recursive(mid + 1, right, vals);

    return node;
  }

 public:
  TreeNode *balanceBST(TreeNode *root) {
    vector<int> vals;

    getVals(root, vals);

    return recursive(0, vals.size() - 1, vals);
  }
};