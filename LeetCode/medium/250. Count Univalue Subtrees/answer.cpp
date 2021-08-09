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

class Solution {
 private:
  int answer = 0;

  bool recursive(TreeNode *node, int parent) {
    if (!node->left && !node->right) {
      answer += 1;
      return true;
    }

    bool isLeftValid = true, isRightValid = true;
    if (node->left) {
      isLeftValid = recursive(node->left, node->val);
      isLeftValid = isLeftValid && node->val == node->left->val;
    }
    if (node->right) {
      isRightValid = recursive(node->right, node->val);
      isRightValid = isRightValid && node->val == node->right->val;
    }

    if (isLeftValid && isRightValid) {
      answer += 1;
      return true;
    }
    return false;
  }

 public:
  int countUnivalSubtrees(TreeNode *root) {
    if (root) recursive(root, root->val);

    return answer;
  }
};

// use parent pass recursive

class Solution {
 private:
  int answer = 0;

  bool recursive(TreeNode *node, int val) {
    if (!node) return true;

    bool isLeftValid = recursive(node->left, node->val);
    bool isRightValid = recursive(node->right, node->val);

    if (!isLeftValid || !isRightValid) return false;

    answer++;
    return node->val == val;
  }

 public:
  int countUnivalSubtrees(TreeNode *root) {
    recursive(root, 0);
    return answer;
  }
};