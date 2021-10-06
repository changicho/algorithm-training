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

class Solution {
 private:
  int answer = INT_MIN;
  int diameter(TreeNode *root) {
    if (!root) return 0;

    int left = diameter(root->left);
    int right = diameter(root->right);

    answer = max(answer, left + right);

    return max(left, right) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root) return 0;

    diameter(root);

    return answer;
  }
};