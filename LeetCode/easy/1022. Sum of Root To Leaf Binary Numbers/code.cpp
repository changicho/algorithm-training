#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// DFS
// time : O(N)
// space : O(H)
class Solution {
 private:
  int recursive(TreeNode* node, int val) {
    int cur = val * 2 + node->val;
    int leftVal = 0, rightVal = 0;
    if (node->left) {
      leftVal = recursive(node->left, cur);
    }
    if (node->right) {
      rightVal = recursive(node->right, cur);
    }

    if (!node->left && !node->right) {
      return cur;
    }
    return leftVal + rightVal;
  }

 public:
  int sumRootToLeaf(TreeNode* root) {
    if (!root) return 0;

    return recursive(root, 0);
  }
};