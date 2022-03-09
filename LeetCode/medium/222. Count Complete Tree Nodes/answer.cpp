#include <algorithm>
#include <cmath>
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

// use brute force
// time : O(N)
// space : O(H)
class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

// use binary search
// time : O(H^2)
// space : O(H)
class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    int leftHeight = 0, rightHeight = 0;
    TreeNode *leftNode = root, *rightNode = root;

    // O(H)
    while (leftNode) {
      leftHeight++;
      leftNode = leftNode->left;
    }
    while (rightNode) {
      rightHeight++;
      rightNode = rightNode->right;
    }

    // full case
    if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
    // O(H)
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};