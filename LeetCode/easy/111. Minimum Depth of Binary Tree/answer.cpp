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

class Solution {
 public:
  int answer = 100001;
  int minDepth(TreeNode *root) {
    findDepth(root, 1);

    if (answer == 100001) answer = 0;
    return answer;
  }

  void findDepth(TreeNode *cur, int depth) {
    if (!cur) {
      return;
    }

    if (!cur->left && !cur->right) {
      answer = min(depth, answer);
      return;
    }

    findDepth(cur->left, depth + 1);
    findDepth(cur->right, depth + 1);
  }
};

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int answer = INT_MAX;

  void recursive(TreeNode *node, int d) {
    if (!node) return;

    if (!node->left && !node->right) {
      answer = min(answer, d);

      return;
    }

    if (node->left) recursive(node->left, d + 1);
    if (node->right) recursive(node->right, d + 1);
  }

 public:
  int minDepth(TreeNode *root) {
    recursive(root, 1);

    if (answer == INT_MAX) return 0;
    return answer;
  }
};