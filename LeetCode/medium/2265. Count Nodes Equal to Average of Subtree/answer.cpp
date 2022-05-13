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
  struct Status {
    int sum, count;
  };
  int equalCount = 0;

  Status recursive(TreeNode *node) {
    Status cur = {node->val, 1};

    if (node->left) {
      Status left = recursive(node->left);

      cur.sum += left.sum;
      cur.count += left.count;
    }
    if (node->right) {
      Status right = recursive(node->right);

      cur.sum += right.sum;
      cur.count += right.count;
    }

    if (node->val == cur.sum / cur.count) {
      equalCount++;
    }

    return cur;
  }

 public:
  int averageOfSubtree(TreeNode *root) {
    if (root) recursive(root);

    return equalCount;
  }
};