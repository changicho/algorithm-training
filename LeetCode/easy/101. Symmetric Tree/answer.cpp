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

// use two queue
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> leftQueue;
    queue<TreeNode *> rightQueue;

    if (root->left) {
      leftQueue.push(root->left);
    }
    if (root->right) {
      rightQueue.push(root->right);
    }
    while (!leftQueue.empty() && !rightQueue.empty()) {
      TreeNode *left = leftQueue.front();
      TreeNode *right = rightQueue.front();
      leftQueue.pop();
      rightQueue.pop();

      if (!left && !right) continue;
      if (!left || !right) return false;
      if (left->val != right->val) return false;

      leftQueue.push(left->left);
      leftQueue.push(left->right);

      rightQueue.push(right->right);
      rightQueue.push(right->left);
    }

    if (!leftQueue.empty() || !rightQueue.empty()) return false;

    return true;
  }
};

// recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;

    if (t1->val != t2->val) return false;
    if (!isMirror(t1->right, t2->left)) return false;
    if (!isMirror(t1->left, t2->right)) return false;

    return true;
  }

 public:
  bool isSymmetric(TreeNode *root) { return isMirror(root, root); }
};

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;

    if (root) q.push(root);

    while (!q.empty()) {
      int size = q.size();

      vector<int> line;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        line.push_back(cur->left ? cur->left->val : -1000);
        if (cur->left) q.push(cur->left);
        line.push_back(cur->right ? cur->right->val : -1000);
        if (cur->right) q.push(cur->right);
      }

      if (line.size() % 2 == 1) return false;
      int left = 0, right = line.size() - 1;
      while (left < right) {
        if (line[left] != line[right]) return false;
        left++;
        right--;
      }
    }

    return true;
  }
};