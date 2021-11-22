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

// use recursive and change node to leaf

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    // move to left
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
      return root;
    }
    // move to right
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
      return root;
    }

    // current node is target to delete
    // leaf node case
    if (!root->left && !root->right) {
      delete root;
      return NULL;
    }
    // one child case
    if (!root->left || !root->right) {
      TreeNode* ret = root->left ? root->left : root->right;
      delete root;
      return ret;
    }
    // two child case
    if (root->left && root->right) {
      // we cen choose left, right whatever
      // just pick the node that has closest value from root->val
      TreeNode* temp = root->right;
      while (temp->left) {
        temp = temp->left;
      }
      root->val = temp->val;
      root->right = deleteNode(root->right, root->val);
    }

    return root;
  }
};

// use iteration

class Solution {
 private:
  void changeChild(TreeNode* parent, TreeNode* child, TreeNode* value) {
    if (child == parent->left) {
      parent->left = value;
    } else if (child == parent->right) {
      parent->right = value;
    }
  }

 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* target = root;
    TreeNode* parent = NULL;

    while (target && target->val != key) {
      parent = target;
      if (key > target->val) {
        target = target->right;
      } else if (key < target->val) {
        target = target->left;
      }
    }

    if (!target) return root;

    // leaf node case
    if (!target->left && !target->right) {
      if (!parent) return NULL;
      changeChild(parent, target, NULL);
      return root;
    }

    // one child case
    if (!target->left || !target->right) {
      TreeNode* ret = target->left ? target->left : target->right;

      if (!parent) return ret;
      changeChild(parent, target, ret);
      return root;
    }

    // two child case
    TreeNode *leafParent = target, *leaf = target->right;
    while (leaf->left) {
      leafParent = leaf;
      leaf = leaf->left;
    }

    target->val = leaf->val;
    changeChild(leafParent, leaf, leaf->right);

    return root;
  }
};