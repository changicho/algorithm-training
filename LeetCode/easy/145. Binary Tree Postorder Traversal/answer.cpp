#include <algorithm>
#include <iostream>
#include <stack>
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

// use recursive

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (root) postOrder(root, ret);

    return ret;
  }
  void postOrder(TreeNode* node, vector<int>& array) {
    if (node->left) postOrder(node->left, array);
    if (node->right) postOrder(node->right, array);
    array.push_back(node->val);
  }
};

// use recursive itself

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ret;

    for (int node : postorderTraversal(root->left)) ret.push_back(node);
    for (int node : postorderTraversal(root->right)) ret.push_back(node);
    if (root) ret.push_back(root->val);

    return ret;
  }
};

// use stack

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* lastNode = NULL;

    while (root || !st.empty()) {
      if (root) {
        st.push(root);
        root = root->left;

        continue;
      }

      TreeNode* node = st.top();
      if (node->right && lastNode != node->right) {
        root = node->right;
        continue;
      }

      ret.push_back(node->val);
      lastNode = node;
      st.pop();
    }
    return ret;
  }
};

// use morris traversal

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* dummy = new TreeNode(0);
    dummy->left = root;
    TreeNode* cur = dummy;

    while (cur) {
      if (!cur->left) {
        cur = cur->right;
        continue;
      }

      TreeNode* pre = cur->left;

      while (pre->right && (pre->right != cur)) {
        pre = pre->right;
      }

      if (!(pre->right)) {
        pre->right = cur;
        cur = cur->left;
      } else {
        reverseAddNodes(cur->left, pre, ret);

        pre->right = NULL;
        cur = cur->right;
      }
    }
    return ret;
  }

 private:
  void reverseNodes(TreeNode* start, TreeNode* end) {
    if (start == end) return;

    TreeNode* x = start;
    TreeNode* y = start->right;
    TreeNode* z;

    while (x != end) {
      z = y->right;
      y->right = x;
      x = y;
      y = z;
    }
  }

  void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& array) {
    reverseNodes(start, end);
    TreeNode* node = end;

    while (true) {
      array.push_back(node->val);

      if (node == start) break;
      node = node->right;
    }

    reverseNodes(end, start);
  }
};