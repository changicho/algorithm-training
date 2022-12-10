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

// use recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  int beforeMax, beforeMin;
  int answer = INT_MIN;

  void recursive(TreeNode *node) {
    if (!node) return;
    int tempMax = beforeMax, tempMin = beforeMin;
    int val = node->val;

    answer = max({answer, abs(val - beforeMax), abs(val - beforeMin)});

    beforeMax = max(beforeMax, val);
    beforeMin = min(beforeMin, val);

    if (node->left) recursive(node->left);
    if (node->right) recursive(node->right);

    beforeMax = tempMax, beforeMin = tempMin;
  }

 public:
  int maxAncestorDiff(TreeNode *root) {
    beforeMax = root->val, beforeMin = root->val;
    recursive(root);

    return answer;
  }
};