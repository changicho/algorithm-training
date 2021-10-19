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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use BFS

class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    queue<TreeNode *> q;
    if (root) q.push(root);

    int first = 0, second = 0;
    int parentFirst = 0, parentSecond = 0;

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        if (cur->val == x) {
          first = step;
        }
        if (cur->val == y) {
          second = step;
        }

        if (cur->left) {
          q.push(cur->left);
          if (cur->left->val == x) parentFirst = cur->val;
          if (cur->left->val == y) parentSecond = cur->val;
        }
        if (cur->right) {
          q.push(cur->right);
          if (cur->right->val == x) parentFirst = cur->val;
          if (cur->right->val == y) parentSecond = cur->val;
        }
      }
      step += 1;
    }

    return first == second && parentFirst != parentSecond;
  }
};