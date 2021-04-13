#include <algorithm>
#include <iostream>
#include <queue>
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

// use DFS

class Solution {
 public:
  bool ret;
  int target;
  bool hasPathSum(TreeNode *root, int targetSum) {
    target = targetSum;

    if (root) {
      recursive(root, 0);
    }

    return ret;
  }

  void recursive(TreeNode *node, int sum) {
    if (ret || !node) return;
    int val = node->val;

    recursive(node->left, sum + val);
    recursive(node->right, sum + val);

    if (!node->left && !node->right && sum + val == target) {
      ret = true;
    }
  }
};

// use BFS

struct Status {
  TreeNode *node;
  int sum;
};

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    queue<Status> q;
    q.push({root, 0});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (!cur.node) continue;
      if (!cur.node->left && !cur.node->right) {
        if (cur.sum + cur.node->val == targetSum) return true;
        continue;
      }

      if (cur.node->left) {
        q.push({cur.node->left, cur.sum + cur.node->val});
      }
      if (cur.node->right) {
        q.push({cur.node->right, cur.sum + cur.node->val});
      }
    }

    return false;
  }
};

// use one function

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;

    if (!root->left && !root->right && targetSum - root->val == 0) return true;

    if (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val)) {
      return true;
    } else {
      return false;
    }
  }
};