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

  // -1:left 0:none 1:right
  void recursive(TreeNode *node, int dir, int count) {
    answer = max(answer, count);

    if (node->left) {
      if (dir == 1 || dir == 0) {
        recursive(node->left, -1, count + 1);
      } else {
        recursive(node->left, -1, 1);
      }
    }
    if (node->right) {
      if (dir == -1 || dir == 0) {
        recursive(node->right, 1, count + 1);
      } else {
        recursive(node->right, 1, 1);
      }
    }
  }

 public:
  int longestZigZag(TreeNode *root) {
    recursive(root, 0, 0);
    return answer;
  }
};