#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
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

// use BFS with recursive

class Solution {
 private:
  int answer = 0;
  void recursive(TreeNode *node, int target, int sum) {
    if (!node) return;

    sum += node->val;
    if (sum == target) {
      answer += 1;
    }

    recursive(node->left, target, sum);
    recursive(node->right, target, sum);
  }

 public:
  int pathSum(TreeNode *root, int targetSum) {
    queue<TreeNode *> q;
    if (root) q.push(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();

      recursive(cur, targetSum, 0);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
    return answer;
  }
};

// use hash map

class Solution {
 private:
  int recursive(TreeNode *root, int curSum, int target,
                unordered_map<int, int> &sums) {
    if (!root) return 0;

    curSum += root->val;
    sums[curSum] += 1;

    int response = sums[curSum - target];

    response += recursive(root->left, curSum, target, sums) +
                recursive(root->right, curSum, target, sums);

    sums[curSum] -= 1;
    return response;
  }

 public:
  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<int, int> sums;
    sums[0] = 1;

    return recursive(root, 0, targetSum, sums);
  }
};