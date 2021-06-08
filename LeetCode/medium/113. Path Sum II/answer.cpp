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

// use DFS

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> answers;
    vector<int> path;

    if (root) {
      path.push_back(root->val);
      recursive(answers, path, root, root->val, targetSum);
    }

    return answers;
  }

  void recursive(vector<vector<int>>& answers, vector<int>& path, TreeNode* node, int curSum, int target) {
    if (!node->left && !node->right) {
      if (curSum == target) answers.push_back(path);

      return;
    }

    if (node->left) {
      int value = node->left->val;
      path.push_back(value);
      recursive(answers, path, node->left, curSum + value, target);
      path.pop_back();
    }

    if (node->right) {
      int value = node->right->val;
      path.push_back(value);
      recursive(answers, path, node->right, curSum + value, target);
      path.pop_back();
    }
  }
};