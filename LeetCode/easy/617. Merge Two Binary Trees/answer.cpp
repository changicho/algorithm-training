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

// use DFS

class Solution {
 private:
  void recursive(TreeNode*& node, TreeNode*& a, TreeNode*& b) {
    if (a) node->val += a->val;
    if (b) node->val += b->val;

    if (a && a->left || b && b->left) {
      TreeNode* aNext = a ? a->left : NULL;
      TreeNode* bNext = b ? b->left : NULL;
      node->left = new TreeNode();
      recursive(node->left, aNext, bNext);
    }

    if (a && a->right || b && b->right) {
      TreeNode* aNext = a ? a->right : NULL;
      TreeNode* bNext = b ? b->right : NULL;
      node->right = new TreeNode();
      recursive(node->right, aNext, bNext);
    }
  }

 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return NULL;
    TreeNode* temp = new TreeNode();

    recursive(temp, root1, root2);

    return temp;
  }
};

///

class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
  }
};