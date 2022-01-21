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
  int answer = 0;

  void recursive(TreeNode *root, int low, int high) {
    // case that value in range
    if (low <= root->val && root->val <= high) {
      answer += root->val;
    }

    // if children's value in range
    if (root->left && low < root->val) recursive(root->left, low, high);
    if (root->right && root->val < high) recursive(root->right, low, high);
  }

 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root) recursive(root, low, high);

    return answer;
  }
};