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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> answer;

    queue<TreeNode *> q;
    if (root) q.push(root);
    bool convert = false;

    while (!q.empty()) {
      vector<int> line;
      for (int i = 0, size = q.size(); i < size; i++) {
        TreeNode *cur = q.front();
        q.pop();

        line.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      if (convert) reverse(line.begin(), line.end());
      convert = !convert;

      answer.push_back(line);
    }

    return answer;
  }
};