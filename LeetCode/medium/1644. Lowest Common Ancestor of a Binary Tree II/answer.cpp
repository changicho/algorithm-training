#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use LCA
// time : O(N)
// space : O(N)
class Solution {
 private:
  unordered_map<TreeNode*, int> depths;
  unordered_map<TreeNode*, TreeNode*> parents;

  void recursive(TreeNode* node, TreeNode* parent, int depth) {
    depths[node] = depth;
    parents[node] = parent;

    if (node->left) {
      recursive(node->left, node, depth + 1);
    }
    if (node->right) {
      recursive(node->right, node, depth + 1);
    }
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    recursive(root, NULL, 0);

    if (depths.count(p) == 0 || depths.count(q) == 0) return NULL;

    while (depths[p] > depths[q]) {
      p = parents[p];
    }
    while (depths[q] > depths[p]) {
      q = parents[q];
    }

    while (p != q) {
      p = parents[p];
      q = parents[q];
    }
    return p;
  }
};

// use LCA
// time : O(N)
// space : O(N)
class Solution {
 private:
  TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (!node) return NULL;
    if (node == p || node == q) return node;

    TreeNode* left = LCA(node->left, p, q);
    TreeNode* right = LCA(node->right, p, q);

    if (left && right) return node;

    if (left) return left;
    if (right) return right;
    return NULL;
  }

  bool isSubtree(TreeNode* node, TreeNode* target) {
    if (!node) return false;
    if (node == target) return true;
    return isSubtree(node->left, target) || isSubtree(node->right, target);
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* answer = LCA(root, p, q);
    if (answer == p) {
      // check if q is in the subtree of p
      return isSubtree(p, q) ? p : NULL;
    } else if (answer == q) {
      // check if p is in the subtree of q
      return isSubtree(q, p) ? q : NULL;
    }
    return answer;
  }
};