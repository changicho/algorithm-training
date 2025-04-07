#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

// use LCA (dfs)
// time : O(N)
// space : O(N)
class Solution {
 private:
  int maxDepth = 0;

  TreeNode* dfs(TreeNode* root, int len) {
    if (!root) return NULL;
    if (maxDepth == len) return root;

    TreeNode* left = dfs(root->left, len + 1);
    TreeNode* right = dfs(root->right, len + 1);

    if (left && right) return root;

    return left ? left : right;
  }

  void getDepth(TreeNode* node, int depth) {
    maxDepth = max(maxDepth, depth);
    if (node->left) getDepth(node->left, depth + 1);
    if (node->right) getDepth(node->right, depth + 1);
  }

 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    getDepth(root, 0);

    return dfs(root, 0);
  }
};