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
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use make binary tree

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder.front());

    int size = preorder.size();
    for (int i = 1; i < size; i++) {
      int num = preorder[i];
      TreeNode* cur = root;
      TreeNode* prev = NULL;

      while (cur) {
        prev = cur;
        if (cur->val < num) {
          cur = cur->right;
        } else {
          cur = cur->left;
        }
      }

      if (prev->val < num) {
        prev->right = new TreeNode(num);
      } else {
        prev->left = new TreeNode(num);
      }
    }

    return root;
  }
};

// use stack

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder.front());
    stack<TreeNode*> s;
    s.push(root);

    for (int i = 1; i < preorder.size(); i++) {
      TreeNode* node = new TreeNode(preorder[i]);
      if (node->val < s.top()->val) {
        s.top()->left = node;
      } else {
        TreeNode* prev;

        while (!s.empty() && s.top()->val < node->val) {
          prev = s.top();
          s.pop();
        }

        prev->right = node;
      }
      s.push(node);
    }

    return root;
  }
};

// use stack (recursive)

class Solution {
 private:
  TreeNode* recursive(vector<int>& preorder, int& index, TreeNode* parent) {
    if (index >= preorder.size() || (parent && preorder[index] > parent->val))
      return NULL;

    TreeNode* node = new TreeNode(preorder[index]);
    index++;

    node->left = recursive(preorder, index, node);
    node->right = recursive(preorder, index, parent);

    return node;
  }

 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* parent = NULL;
    int index = 0;

    return recursive(preorder, index, parent);
  }
};