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

// use BFS

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> answer;

    queue<TreeNode *> q;
    if (root) q.push(root);

    while (!q.empty()) {
      vector<int> level;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *cur = q.front();
        q.pop();

        level.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      answer.push_back(level);
    }

    return answer;
  }
};

// use DFS

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> answer;

    if (root) recursive(answer, root, 0);

    return answer;
  }

  void recursive(vector<vector<int>> &answer, TreeNode *node, int level) {
    if (answer.size() <= level) {
      answer.resize(level + 1);
    }

    answer[level].push_back(node->val);

    if (node->left) recursive(answer, node->left, level + 1);
    if (node->right) recursive(answer, node->right, level + 1);
  }
};