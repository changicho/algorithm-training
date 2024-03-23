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
  int answer = 0;

  long long recursive(TreeNode *node) {
    long long childrenSum = 0;
    if (node->left) childrenSum += recursive(node->left);
    if (node->right) childrenSum += recursive(node->right);

    if (node->val == childrenSum) answer++;

    return childrenSum + node->val;
  }

 public:
  int equalToDescendants(TreeNode *root) {
    if (root) recursive(root);

    return answer;
  }
};