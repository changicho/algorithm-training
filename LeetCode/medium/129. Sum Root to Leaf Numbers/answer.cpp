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
 private:
  int answer = 0;

 public:
  int sumNumbers(TreeNode *root) {
    recursive(root, 0);

    return answer;
  }

  void recursive(TreeNode *node, int sum) {
    if (!node) return;

    sum = sum * 10 + node->val;

    if (!node->left && !node->right) {
      answer += sum;
      return;
    }

    recursive(node->left, sum);
    recursive(node->right, sum);
  }
};

// use BFS

class Solution {
 private:
  struct Status {
    TreeNode *node;
    int sum;
  };

 public:
  int sumNumbers(TreeNode *root) {
    int answer = 0;

    queue<Status> q;
    q.push({root, 0});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      TreeNode *node = cur.node;
      if (!node) continue;
      int sum = cur.sum * 10 + node->val;

      if (!node->left && !node->right) {
        answer += sum;
        continue;
      }

      q.push({node->left, sum});
      q.push({node->right, sum});
    }

    return answer;
  }
};