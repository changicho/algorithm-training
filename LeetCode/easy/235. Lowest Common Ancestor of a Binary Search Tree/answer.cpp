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

// use iteration

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *first = root, *second = root;
    TreeNode* head = root;

    while (first == second) {
      head = first;
      if (head->val < p->val) {
        first = first->right;
      } else if (head->val > p->val) {
        first = first->left;
      }

      if (head->val < q->val) {
        second = second->right;
      } else if (head->val > q->val) {
        second = second->left;
      }
    }

    return head;
  }
};

// use recursive

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    } else if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }

    return root;
  }
};