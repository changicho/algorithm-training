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

// use BFS null checking

class Solution {
 public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;

    if (root) q.push(root);
    vector<int> paths;

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();

      if (cur == NULL) {
        paths.push_back(-1);
      } else {
        paths.push_back(cur->val);
      }

      if (cur) {
        q.push(cur->left);
        q.push(cur->right);
      }
    }

    bool foundNull = false;

    for (int &p : paths) {
      if (p == -1) {
        foundNull = true;
      } else if (foundNull) {
        return false;
      }
    }

    return true;
  }
};

// use DFS

class Solution {
 private:
  int count(TreeNode *node) {
    if (!node) return 0;

    int left = count(node->left);
    int right = count(node->right);

    // to check x = 2^k - 1
    // we use x & (x + 1) == 0
    if ((left & (left + 1)) == 0 && left / 2 <= right && right <= left) {
      return left + right + 1;
    }
    if ((right & (right + 1)) == 0 && right <= left && left <= right * 2 + 1) {
      return left + right + 1;
    }

    return -1;
  }

 public:
  bool isCompleteTree(TreeNode *root) {
    bool answer = count(root) >= 0;

    return answer;
  }
};