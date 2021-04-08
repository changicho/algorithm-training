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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use DFS

class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    bool answer = true;
    int height = getHeight(root, 0, answer);

    return answer;
  }

  int getHeight(TreeNode *cur, int height, bool &answer) {
    if (!cur) return height - 1;

    int left = getHeight(cur->left, height + 1, answer);
    int right = getHeight(cur->right, height + 1, answer);

    if (abs(left - right) > 1) answer = false;

    return max(left, right);
  }
};