#include <algorithm>
#include <iostream>
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

// use inOrder (space optimized)
// time : O(N)
// space : O(H)
class Solution {
 private:
  int answer = INT_MAX;
  int prev = -1;

  void recursive(TreeNode *node) {
    if (!node) return;

    recursive(node->left);

    if (prev != -1) answer = min(answer, abs(node->val - prev));
    prev = node->val;

    recursive(node->right);
  }

 public:
  int minDiffInBST(TreeNode *root) {
    recursive(root);

    return answer;
  }
};