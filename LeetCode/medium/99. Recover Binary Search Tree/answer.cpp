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
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// use inOrder with array

class Solution {
 public:
  vector<TreeNode*> array;
  void recoverTree(TreeNode* root) {
    recursive(root);

    vector<TreeNode*> errors;
    int size = array.size();
    for (int i = 0; i < size; i++) {
      if (i - 1 >= 0 && array[i - 1]->val >= array[i]->val) {
        errors.push_back(array[i]);
      }

      if (i + 1 < size && array[i]->val >= array[i + 1]->val) {
        errors.push_back(array[i]);
      }
    }

    swap(errors.front()->val, errors.back()->val);
  }

  void recursive(TreeNode* node) {
    if (!node) return;

    recursive(node->left);
    array.push_back(node);
    recursive(node->right);
  }
};

// use inOrder

class Solution {
 public:
  TreeNode* first;
  TreeNode* second;
  TreeNode* prev = NULL;

  void recoverTree(TreeNode* root) {
    recursive(root);

    swap(first->val, second->val);
  }

  void recursive(TreeNode* node) {
    if (!node) return;

    recursive(node->left);

    if (!first && prev && prev->val >= node->val) first = prev;
    if (first && prev && prev->val >= node->val) second = node;
    prev = node;

    recursive(node->right);
  }
};

// use Morris Traversal

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    // Morris Traversal
    TreeNode* temp = NULL;
    while (root) {
      if (root->left) {
        // connect threading for root
        temp = root->left;
        while (temp->right && temp->right != root) {
          temp = temp->right;
        }

        // the threading already exists
        if (temp->right) {
          if (prev && prev->val > root->val) {
            if (!first) {
              first = prev;
              second = root;
            } else {
              second = root;
            }
          }
          prev = root;

          temp->right = NULL;
          root = root->right;
        } else {
          // construct the threading
          temp->right = root;
          root = root->left;
        }
        continue;
      }

      if (prev && prev->val > root->val) {
        if (!first) {
          first = prev;
          second = root;
        } else {
          second = root;
        }
      }
      prev = root;
      root = root->right;
    }

    swap(first->val, second->val);
  }
};