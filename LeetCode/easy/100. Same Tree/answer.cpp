#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use BFS
// time : O(N)
// space :O(N)
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;

    q1.push(p);
    q2.push(q);

    while (!q1.empty() && !q2.empty()) {
      TreeNode* cur1 = q1.front();
      TreeNode* cur2 = q2.front();

      q1.pop();
      q2.pop();

      if (!cur1 && !cur2) {
        continue;
      }
      if (!cur1 || !cur2) {
        return false;
      }
      if (cur1->val != cur2->val) {
        return false;
      }

      q1.push(cur1->left);
      q1.push(cur1->right);

      q2.push(cur2->left);
      q2.push(cur2->right);
    }

    return true;
  }
};

// use DFS
// time : O(N)
// space :O(N)
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!q || !p) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }

    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
  }
};