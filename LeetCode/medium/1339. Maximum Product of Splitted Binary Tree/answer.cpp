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
// space : O(H)
class Solution {
 private:
  long long MOD = 1e9 + 7;
  long long sum = 0;
  long long answer = 0;

  void makeSum(TreeNode *node) {
    if (!node) return;
    sum += node->val;

    if (node->left) makeSum(node->left);
    if (node->right) makeSum(node->right);
  }

  int recursive(TreeNode *node) {
    if (!node) return 0;
    long long ret = node->val;

    if (node->left) {
      ret += recursive(node->left);
    }
    if (node->right) {
      ret += recursive(node->right);
    }

    long long cur = (ret * (sum - ret));

    answer = max(answer, cur);
    return ret;
  }

 public:
  int maxProduct(TreeNode *root) {
    makeSum(root);

    recursive(root);

    return answer % MOD;
  }
};
