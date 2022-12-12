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
// space : O(N + H)
class Solution {
 private:
  void recursive(TreeNode *node, vector<int> &visited) {
    if (!node) return;
    bool hasChild = node->left || node->right;

    if (node->left) {
      recursive(node->left, visited);
    }
    if (node->right) {
      recursive(node->right, visited);
    }
    if (!hasChild) {
      visited.emplace_back(node->val);
    }
  }

  vector<int> getLeafSequence(TreeNode *root) {
    vector<int> sequence;
    recursive(root, sequence);
    return sequence;
  }

 public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> sequence1 = getLeafSequence(root1),
                sequence2 = getLeafSequence(root2);

    return sequence1 == sequence2;
  }
};