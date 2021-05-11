#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use recursive inOrder

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;

    if (root) inOrder(root, ret);

    return ret;
  }

  void inOrder(TreeNode *node, vector<int> &array) {
    if (node->left) inOrder(node->left, array);
    array.push_back(node->val);
    if (node->right) inOrder(node->right, array);
  }
};

// use stack

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;

    TreeNode *cur = root;
    while (cur || !s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      ret.push_back(cur->val);
      cur = cur->right;
    }

    return ret;
  }
};

// use morris traversal

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;

    TreeNode *cur = root;
    TreeNode *pre;

    while (cur) {
      if (!cur->left) {
        ret.push_back(cur->val);
        cur = cur->right;
      } else {
        pre = cur->left;

        while (pre->right) {
          pre = pre->right;
        }

        pre->right = cur;
        TreeNode *temp = cur;
        cur = cur->left;
        temp->left = NULL;
      }
    }

    return ret;
  }
};
