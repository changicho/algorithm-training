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
// time : O(N^2)
// space : O(H)
class Solution {
 private:
  int answer = 0;

  void recursive(TreeNode *node, int target, long long sum) {
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

// use DFS with recursive
// time : O(N^2)
// space : O(H)
class Solution {
 private:
  int countSame = 0;

  void recursive(TreeNode *node, long long curSum, long long target) {
    if (!node) return;

    curSum += node->val;
    if (curSum == target) countSame++;

    if (node->left) recursive(node->left, curSum, target);
    if (node->right) recursive(node->right, curSum, target);
  }

  void startNode(TreeNode *node, int target) {
    if (!node) return;

    recursive(node, 0, target);

    if (node->left) startNode(node->left, target);
    if (node->right) startNode(node->right, target);
  }

 public:
  int pathSum(TreeNode *root, int targetSum) {
    startNode(root, targetSum);

    return countSame;
  }
};

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 private:
  int countSame = 0;

  unordered_map<long long, int> sums;

  void recursive(TreeNode *node, long long curSum, int target) {
    curSum += node->val;

    if (curSum == target) countSame++;
    countSame += sums[curSum - target];
    sums[curSum] += 1;

    if (node->left) recursive(node->left, curSum, target);
    if (node->right) recursive(node->right, curSum, target);

    sums[curSum] -= 1;
  }

 public:
  int pathSum(TreeNode *root, int targetSum) {
    if (root) recursive(root, 0, targetSum);

    return countSame;
  }
};