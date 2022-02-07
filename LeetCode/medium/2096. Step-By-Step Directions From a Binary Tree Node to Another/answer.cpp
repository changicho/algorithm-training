#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use LCA

class Solution {
 private:
  unordered_map<int, TreeNode*> table;
  unordered_map<int, TreeNode*> parents;
  unordered_map<int, int> depths;

  void recursive(TreeNode* node, int depth) {
    if (!node) return;

    depths[node->val] = depth;
    table[node->val] = node;

    if (node->left) {
      parents[node->left->val] = node;
      recursive(node->left, depth + 1);
    }
    if (node->right) {
      parents[node->right->val] = node;
      recursive(node->right, depth + 1);
    }
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    // search LCA
    // find LCA -> startVal, reverse it path
    // find LCA -> destVal, reverse it path

    recursive(root, 0);

    TreeNode *start = table[startValue], *dest = table[destValue];

    string startToLCA = "", destToLCA = "";

    // trim depth of start
    while (depths[start->val] > depths[dest->val]) {
      startToLCA += "U";
      start = parents[start->val];
    }
    // trim depth of dest
    while (depths[dest->val] > depths[start->val]) {
      TreeNode* parent = parents[dest->val];
      if (parent->left && parent->left->val == dest->val) {
        destToLCA += "L";
      } else if (parent->right && parent->right->val == dest->val) {
        destToLCA += "R";
      }
      dest = parents[dest->val];
    }

    // move one by one
    while (start->val != dest->val) {
      startToLCA += "U";

      TreeNode* parent = parents[dest->val];
      if (parent->left && parent->left->val == dest->val) {
        destToLCA += "L";
      } else if (parent->right && parent->right->val == dest->val) {
        destToLCA += "R";
      }

      start = parents[start->val];
      dest = parents[dest->val];
    }

    reverse(destToLCA.begin(), destToLCA.end());
    string answer = startToLCA + destToLCA;
    return answer;
  }
};

// use LCA with path, prefix delete

class Solution {
 private:
  bool find(TreeNode* node, int val, string& path) {
    if (node->val == val) return true;

    if (node->left && find(node->left, val, path)) {
      path.push_back('L');
    } else if (node->right && find(node->right, val, path)) {
      path.push_back('R');
    }

    return !path.empty();
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string startPath, destPath;

    // fill start, dest path
    find(root, startValue, startPath);
    find(root, destValue, destPath);

    while (!startPath.empty() && !destPath.empty() &&
           startPath.back() == destPath.back()) {
      startPath.pop_back();
      destPath.pop_back();
    }

    reverse(destPath.begin(), destPath.end());
    return string(startPath.length(), 'U') + destPath;
  }
};