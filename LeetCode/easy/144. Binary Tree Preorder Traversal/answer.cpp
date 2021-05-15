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

// use recursive

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;

    if (root) {
      preOrder(root, ret);
    }

    return ret;
  }

  void preOrder(TreeNode *node, vector<int> &array) {
    array.push_back(node->val);

    if (node->left) preOrder(node->left, array);
    if (node->right) preOrder(node->right, array);
  }
};

// use recursive one line

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (!root) return {};

    ret.push_back(root->val);
    for (int node : preorderTraversal(root->left)) {
      ret.push_back(node);
    }
    for (int node : preorderTraversal(root->right)) {
      ret.push_back(node);
    }

    return ret;
  }
};

// use stack

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> st;

    if (root) st.push(root);

    while (!st.empty()) {
      TreeNode *cur = st.top();
      st.pop();

      ret.push_back(cur->val);

      if (cur->right) st.push(cur->right);
      if (cur->left) st.push(cur->left);
    }

    return ret;
  }
};