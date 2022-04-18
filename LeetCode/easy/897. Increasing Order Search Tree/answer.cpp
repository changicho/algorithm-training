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

// use array
// time : O(N)
// space : O(N)
class Solution {
  void recursive(TreeNode* node, vector<int>& v) {
    if (node->left) recursive(node->left, v);
    v.push_back(node->val);
    if (node->right) recursive(node->right, v);
  }

 public:
  TreeNode* increasingBST(TreeNode* root) {
    vector<int> visited;
    if (root) recursive(root, visited);

    TreeNode* head = new TreeNode();
    TreeNode* cur = head;

    for (int& v : visited) {
      cur->right = new TreeNode(v);
      cur = cur->right;
    }

    return head->right;
  }
};

// use inorder
// time : O(N)
// space : O(H)
class Solution {
  TreeNode* cur = NULL;

  void recursive(TreeNode* node) {
    if (node->left) recursive(node->left);
    node->left = NULL;
    cur->right = node;
    cur = node;
    if (node->right) recursive(node->right);
  }

 public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode* head = new TreeNode();
    cur = head;

    if (root) recursive(root);

    return head->right;
  }
};