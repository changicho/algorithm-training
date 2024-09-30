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

// use recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  int recursive(TreeNode *node) {
    int coins = node->val;
    int needs = 1;

    if (node->left) {
      coins += recursive(node->left);
    }
    if (node->right) {
      coins += recursive(node->right);
    }

    coins -= needs;

    answer += abs(coins);

    return coins;
  }

 public:
  int distributeCoins(TreeNode *root) {
    recursive(root);

    return answer;
  }
};