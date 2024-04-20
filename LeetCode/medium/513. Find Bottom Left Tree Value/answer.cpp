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

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int depth = -1;
  int answer = -1;

  void recursive(TreeNode *node, int depth) {
    if (depth > this->depth) {
      answer = node->val;
      this->depth = depth;
    }

    if (node->left) recursive(node->left, depth + 1);
    if (node->right) recursive(node->right, depth + 1);
  }

 public:
  int findBottomLeftValue(TreeNode *root) {
    recursive(root, 0);

    return answer;
  }
};

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    int answer = root->val;
    while (!q.empty()) {
      int size = q.size();

      answer = q.front()->val;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
    }
    return answer;
  }
};