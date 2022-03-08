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

// use DFS
// time : O(N)
// space : O(H)
class Solution {
 private:
  int answer = INT_MIN;

  int getMaxPathSum(TreeNode *node) {
    if (!node) return 0;

    int leftMax = getMaxPathSum(node->left);
    int rightMax = getMaxPathSum(node->right);

    // pick left, pick right, pick cur node
    int cur = max({node->val, leftMax + node->val, rightMax + node->val});

    // update answer
    // also check current node is root of subTree case
    answer = max({answer, cur, leftMax + rightMax + node->val});

    return cur;
  }

 public:
  int maxPathSum(TreeNode *root) {
    getMaxPathSum(root);

    return answer;
  }
};