#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use while

class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* upper = NULL;
    if (!root || !p) return upper;

    while (root) {
      if (root->val <= p->val) {
        root = root->right;
      } else {
        upper = root;
        root = root->left;
      }
    }

    return upper;
  }
};

// use recursive

class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (!root || !p) return NULL;

    if (root->val <= p->val) {
      return inorderSuccessor(root->right, p);
    }

    TreeNode* ret = inorderSuccessor(root->left, p);
    return ret ? ret : root;
  }
};