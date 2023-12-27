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
// space : O(N)
class Solution {
 private:
  double answer = 0;

  pair<int, long long> recursive(TreeNode *node) {
    int count = 1;
    long long sum = node->val;

    if (node->left) {
      auto ret = recursive(node->left);
      count += ret.first;
      sum += ret.second;
    }
    if (node->right) {
      auto ret = recursive(node->right);
      count += ret.first;
      sum += ret.second;
    }

    answer = max(answer, (double)sum / count);
    return {count, sum};
  }

 public:
  double maximumAverageSubtree(TreeNode *root) {
    if (root) recursive(root);

    return answer;
  }
};