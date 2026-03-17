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

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  pair<TreeNode*, int> dfs(TreeNode* node) {
    if (!node) return {NULL, 0};

    pair<TreeNode*, int> left, right;
    left = dfs(node->left);
    right = dfs(node->right);

    if (left.second > right.second) return {left.first, left.second + 1};
    if (right.second > left.second) return {right.first, right.second + 1};
    return {node, left.second + 1};
  }

 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).first; }
};