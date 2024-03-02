#include <algorithm>
#include <climits>
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

// use BFS by step
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    if (root) q.push(root);

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      bool isEven = step % 2 == 0;
      int before = isEven ? INT_MIN : INT_MAX;

      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        int num = cur->val;
        if (isEven) {
          if (num % 2 == 0) return false;
          if (before >= num) return false;
        } else {
          if (num % 2 == 1) return false;
          if (before <= num) return false;
        }
        before = num;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      step++;
    }

    return true;
  }
};