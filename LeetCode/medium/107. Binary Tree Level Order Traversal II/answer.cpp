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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> answers;

    queue<TreeNode *> q;
    if (root) q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> line;

      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        line.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      answers.push_back(line);
    }

    reverse(answers.begin(), answers.end());
    return answers;
  }
};